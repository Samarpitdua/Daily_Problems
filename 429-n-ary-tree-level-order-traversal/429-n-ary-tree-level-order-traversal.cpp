/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        vector<int> temp;
        queue<Node* > q;
        if(! root)
            return ans;
        q.push(root);
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                Node* temp2 = q.front();
                temp.push_back(temp2 -> val);
                q.pop();
                for(auto x : temp2 -> children)
                {
                    q.push(x);
                }
            }
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
};