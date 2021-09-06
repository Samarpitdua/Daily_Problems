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
    void levelOrder(TreeNode* root,vector<vector<int>>& v)
    {
        vector<int>ans;
        if(!root)
            return;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            ans.clear();
            int sz=q.size();
            while(sz--)
            {
                TreeNode* temp=q.front();
                ans.push_back(temp->val);
                q.pop();
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
            v.push_back(ans);
        }
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
     vector<vector<int>>v;
        levelOrder(root,v);
        reverse(v.begin(),v.end());
        return v;
    }
};
