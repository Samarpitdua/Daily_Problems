//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool areAnagrams(Node *root1, Node *root2)
    {
        vector<vector<int>> v , v2;
        queue<Node*> q1 , q2;
        if(!root1 and !root2)
        return 1;
        if(!root1 or !root2)
        return 0;
        q1.push(root1);
        q2.push(root2);
        while(!q1.empty())
        {
            int sz = q1.size();
            vector<int> temp;
            while(sz--)
            {
                auto y = q1.front();
                temp.push_back(y -> data);
                q1.pop();
                if(y -> left)
                q1.push(y -> left);
                if(y -> right)
                q1.push(y -> right);
            }
            v.push_back(temp);
        }
        while(!q2.empty())
        {
            int sz = q2.size();
            vector<int> temp;
            while(sz--)
            {
                auto y = q2.front();
                temp.push_back(y -> data);
                q2.pop();
                if(y -> left)
                q2.push(y -> left);
                if(y -> right)
                q2.push(y -> right);
            }
            v2.push_back(temp);
        }
        if(v.size() != v2.size())
        {
            return false;
        }
        for(int i = 0 ; i < v.size() ;i++)
        {
            sort(v[i].begin() , v[i].end());
            sort(v2[i].begin() , v2[i].end());
            if(v[i] != v2[i])
            return false;
        }
        return true;
    
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/
int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string treeString1, treeString2;
        getline(cin, treeString1);
        Node *root1 = buildTree(treeString1);
        getline(cin, treeString2);
        Node *root2 = buildTree(treeString2);
        Solution ob;
        cout << ob.areAnagrams(root1, root2) << endl;
    }
    return 0;
}

// } Driver Code Ends