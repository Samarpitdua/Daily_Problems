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
    void solve(TreeNode* root , int& ct , int maxi)
    {
        if(!root)
            return;
        if(root -> val >= maxi)
            ct++;
        maxi = max(maxi , root -> val);
        solve(root -> left, ct , maxi);
        solve(root -> right, ct , maxi);
        
    }
    int goodNodes(TreeNode* root) {
        int maxi = root -> val;
        int ct = 0;
        solve(root , ct , maxi);
        return ct;
        
    }
};