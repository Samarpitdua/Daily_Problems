/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root , TreeNode* &ans , int& f , TreeNode* p)
    {
        if(!root)
            return ;
        solve(root -> left , ans , f , p);
        if(f == 1)
        {
            f = 2;
            ans = root;
            return;
        }
        if(root == p)
        {
            f = 1;
        }
        solve(root -> right , ans , f , p);
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* ans = NULL;
        int f = 0;
        solve(root , ans , f , p);
        return ans;
    }
};