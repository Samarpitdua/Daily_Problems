/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* node , unordered_map<Node* , Node*>& mp)
    {
        if(!node)
            return NULL;
        Node* clone = new Node(node -> val);
        mp[node] = clone;
        vector<Node*> temp;
        for(auto child : node -> neighbors)
        {
            if(mp.find(child) != mp.end())
            {
                temp.push_back(mp[child]);
            }
            else
            {
                temp.push_back(dfs(child , mp));
            }
        }
        clone -> neighbors = temp; 
        return clone;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node* , Node*> mp;
        if(!node)
            return node;
        if(!node -> neighbors.size())
        {
            Node* clone = new Node(node -> val);
            return clone;
        }
        return dfs(node , mp);
        
        
    }
};