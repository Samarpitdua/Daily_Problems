// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  Node* levelorder(Node* root , int target ,map<Node* , Node* >& mp)
  {
      if(!root)
        return root;
    queue<Node* > q;
    q.push(root);
    //mp[root] = NULL;
    Node* res;
    while(!q.empty())
    {
        int sz = q.size();
        while(sz--)
        {
            Node* temp = q.front();
            q.pop();
            if(temp -> data == target)
                res = temp;
            if(temp -> left)
            {
             //   cout<<temp->left->data<<" ";
                mp[temp -> left] = temp;
                q.push(temp -> left);
            }
            if(temp -> right)
            {
               // cout<<temp->right->data<<" ";
                mp[temp -> right] = temp;
                q.push(temp -> right);
            }
        }
    }
    return res;
        
  }
  int maxTime(map<Node* , Node* > mp , Node* targets)
  {
      queue<Node* > q;
      q.push(targets);
      map<Node* , int>vis;
      vis[targets] = 1;
      int timee = 0;
      while(!q.empty())
      {
          int sz = q.size() , maxi = 0;
          while(sz--)
          {
            Node* temp = q.front();
            q.pop();
            if(temp -> left and !vis[temp -> left])
            {
                q.push(temp -> left);
                 vis[temp -> left] = 1;
                 maxi = 1;
            }
            if(temp -> right and !vis[temp -> right])
            {
                q.push(temp -> right);
                 vis[temp -> right] = 1;
                 maxi = 1;
            }
            if(mp[temp]  and !vis[mp[temp]])
            {
        //        cout<<temp -> data<<"\n";
                q.push(mp[temp]);
                vis[mp[temp]] = 1;
                maxi = 1;
            }
      }
      if(maxi)
      timee++;
    }
      return timee;
  }
    int minTime(Node* root, int target) 
    {
        map<Node* , Node* > mp;
        Node* targets = levelorder(root , target , mp);
        
        return maxTime(mp , targets);
        // Your code goes here
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends