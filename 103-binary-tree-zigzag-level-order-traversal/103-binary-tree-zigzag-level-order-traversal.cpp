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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v;
        vector<int> ans;
        queue<TreeNode*> q;
        if(!root)
            return v;
        q.push(root);
        int h = 0;
        while(!q.empty())
        {
            ans.clear();
            int sz = q.size();
            for(int i = 0; i < sz;i++)
            {
                ans.push_back(q.front() -> val);
                TreeNode * temp = q.front();
                if(temp -> left)
                    q.push(temp -> left);
                if(temp -> right)
                    q.push(temp -> right);
                q.pop();
            }
            if(h == 1)
            reverse(ans.begin() , ans.end());
            h ^= 1;
            v.push_back(ans);
        }
        return v;
    }
};