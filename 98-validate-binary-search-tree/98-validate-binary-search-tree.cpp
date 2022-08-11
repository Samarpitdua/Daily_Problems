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
    bool solve(long long int maxi , long long int mini , TreeNode* root){
        if(!root)
            return true;
        if(root -> val > mini and root -> val < maxi){
            return solve(root -> val , mini , root -> left) and solve(maxi , root -> val , root -> right);
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        long long int maxi = 1e16 , mini = -1e16;
        return solve(maxi , mini , root);
    }
};