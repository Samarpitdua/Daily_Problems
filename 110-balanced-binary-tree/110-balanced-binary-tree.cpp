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
    int solve(TreeNode* root)
    {
        if(!root)
            return 0;
        int l = solve(root -> left);
        int r = solve(root -> right);
        if(l == -1 or r == -1)
            return -1;
        if(abs(l - r) > 1)
            return -1;
        else
            return 1 + max(l , r);
        
    }
    bool isBalanced(TreeNode* root) {
        if(solve(root) == -1)
            return false;
        return true;
    }
};