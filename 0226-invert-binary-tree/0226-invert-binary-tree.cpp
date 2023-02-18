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
    void solve(TreeNode* p){
        if(!p)
            return;
        swap(p -> left, p -> right);
        solve(p -> left);
        solve(p -> right);
        
    }
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return root;
        solve(root);
        return root;
    }
    
};