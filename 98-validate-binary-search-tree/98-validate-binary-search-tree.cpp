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
    bool solve(TreeNode* root , long long int maxi , long long int mini)
    {
        if(!root)
            return true;
        if(root -> val >= maxi or root -> val <= mini)
            return false;
        return solve(root -> left , root -> val , mini) and solve(root -> right , maxi , root -> val);
    }
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        long long int maxi = 1e18 , mini = -1e18;
        return solve(root , maxi , mini);
        
    }
};