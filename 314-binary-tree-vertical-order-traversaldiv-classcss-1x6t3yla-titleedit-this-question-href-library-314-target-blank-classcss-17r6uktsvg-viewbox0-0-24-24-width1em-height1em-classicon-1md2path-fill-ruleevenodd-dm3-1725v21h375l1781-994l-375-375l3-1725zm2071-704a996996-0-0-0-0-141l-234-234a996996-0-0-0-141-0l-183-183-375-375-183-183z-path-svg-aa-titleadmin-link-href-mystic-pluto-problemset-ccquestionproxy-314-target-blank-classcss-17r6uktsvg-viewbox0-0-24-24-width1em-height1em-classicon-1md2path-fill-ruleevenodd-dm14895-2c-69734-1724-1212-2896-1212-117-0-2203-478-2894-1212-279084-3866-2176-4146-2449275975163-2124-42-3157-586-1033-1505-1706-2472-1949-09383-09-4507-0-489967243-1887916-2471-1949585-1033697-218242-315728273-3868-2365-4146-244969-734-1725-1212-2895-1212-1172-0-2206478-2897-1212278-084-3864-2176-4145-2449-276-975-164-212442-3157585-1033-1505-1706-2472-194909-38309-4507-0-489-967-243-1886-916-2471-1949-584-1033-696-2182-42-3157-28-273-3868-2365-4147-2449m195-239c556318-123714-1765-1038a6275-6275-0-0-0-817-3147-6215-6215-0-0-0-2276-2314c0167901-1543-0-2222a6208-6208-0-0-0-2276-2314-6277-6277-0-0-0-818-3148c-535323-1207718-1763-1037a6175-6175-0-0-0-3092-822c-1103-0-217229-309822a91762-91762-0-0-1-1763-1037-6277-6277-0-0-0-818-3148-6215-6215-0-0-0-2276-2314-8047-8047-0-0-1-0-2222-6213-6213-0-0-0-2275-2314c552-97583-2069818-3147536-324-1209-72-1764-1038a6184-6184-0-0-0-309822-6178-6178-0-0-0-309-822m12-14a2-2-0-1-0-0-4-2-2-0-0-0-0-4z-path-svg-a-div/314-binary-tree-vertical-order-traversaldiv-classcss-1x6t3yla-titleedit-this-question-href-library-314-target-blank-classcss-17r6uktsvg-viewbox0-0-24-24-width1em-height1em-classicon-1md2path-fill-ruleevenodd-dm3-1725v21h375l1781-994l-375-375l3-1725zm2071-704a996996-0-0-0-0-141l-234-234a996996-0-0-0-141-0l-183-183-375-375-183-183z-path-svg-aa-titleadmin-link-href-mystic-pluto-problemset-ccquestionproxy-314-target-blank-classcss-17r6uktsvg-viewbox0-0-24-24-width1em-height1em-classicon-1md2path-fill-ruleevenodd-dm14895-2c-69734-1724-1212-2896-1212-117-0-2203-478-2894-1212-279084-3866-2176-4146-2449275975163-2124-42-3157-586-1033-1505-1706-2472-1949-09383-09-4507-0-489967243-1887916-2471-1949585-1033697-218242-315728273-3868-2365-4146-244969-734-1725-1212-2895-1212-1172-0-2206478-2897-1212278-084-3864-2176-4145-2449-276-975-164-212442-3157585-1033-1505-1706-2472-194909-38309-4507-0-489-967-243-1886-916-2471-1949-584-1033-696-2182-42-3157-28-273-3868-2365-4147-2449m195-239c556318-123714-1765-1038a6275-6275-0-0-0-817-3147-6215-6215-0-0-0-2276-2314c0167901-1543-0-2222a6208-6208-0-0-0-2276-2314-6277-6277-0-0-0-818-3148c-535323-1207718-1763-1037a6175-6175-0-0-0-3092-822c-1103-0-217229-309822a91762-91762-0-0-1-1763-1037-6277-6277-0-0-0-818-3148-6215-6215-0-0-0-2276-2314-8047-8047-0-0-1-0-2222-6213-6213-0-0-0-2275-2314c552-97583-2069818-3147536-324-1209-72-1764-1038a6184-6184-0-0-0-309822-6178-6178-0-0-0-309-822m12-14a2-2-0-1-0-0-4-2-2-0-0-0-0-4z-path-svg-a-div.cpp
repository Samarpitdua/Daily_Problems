/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        map<int , vector<int>> mp;
        queue<pair<TreeNode* , pair<int , int>>> q;
        q.push({root , {0 , 0}});
        while(!q.empty())
        {
            auto temp = q.front();
            q.pop();
            int x = temp.second.first;
            int y = temp.second.second;
            mp[x].push_back(temp.first -> val);
            if(temp.first -> left)
                q.push({temp.first -> left , {x - 1 , y + 1}});
            if(temp.first -> right)
                q.push({temp.first -> right , {x + 1 , y + 1}});
        }
        for(auto x : mp){
            ans.push_back(x.second);
        }
        return ans;
        
    }
};