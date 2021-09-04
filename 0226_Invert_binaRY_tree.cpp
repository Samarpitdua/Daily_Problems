class Solution {
public:
    void solve(TreeNode* root)
    {
        if(!root)
            return;
        swap(root->left,root->right);
        solve(root->left);
        solve(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return root;
        solve(root);
        return root;
        
    }
};
