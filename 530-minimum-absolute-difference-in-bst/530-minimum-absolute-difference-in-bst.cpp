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
    void solve(TreeNode* root , int& mini , int& vp)
    {
        if(!root)
            return;
        if(root -> left)
        {
            // vp = root -> val;
            solve(root -> left , mini , vp);
        }
        if(vp >= 0)
        {
            mini = min(mini , abs(root -> val - vp));
        }
         vp = root -> val;
        if(root -> right)
        {
            // vp = root -> val;
            solve(root -> right , mini , vp);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        int mini = INT_MAX;
        int vp = -1;
        solve(root , mini , vp);
        return mini;
    }
};