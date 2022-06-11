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
    int solve(TreeNode* root , int& sum)
    {
        if(!root)
            return 0;
        int l = solve(root->left , sum);
        int r = solve(root->right , sum);
        sum += abs(l - r);
        return l + r + root -> val;
    }
    int findTilt(TreeNode* root) {
        int sum = 0;
        int y =  solve(root , sum);
        // rreturn 
        return sum;
    }
};