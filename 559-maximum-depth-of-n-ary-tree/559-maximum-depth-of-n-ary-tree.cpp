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
    int maxDepth(Node* root) {
        int ans = 0;
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
                q.pop();
                for(auto x : temp2 -> children)
                {
                    q.push(x);
                }
            }
            ans++;
        }
        return ans;
        
    }
};