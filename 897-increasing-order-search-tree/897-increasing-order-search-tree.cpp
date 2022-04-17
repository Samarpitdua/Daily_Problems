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
    void inorder(TreeNode* root , TreeNode* &prev , TreeNode* & ans)
    {
        if(!root)
            return;
        inorder(root -> left , prev , ans);
        if(prev)
            prev -> right = root;
        else
            ans = root;
        prev = root;
        root -> left = NULL;
        inorder(root -> right , prev , ans);
        
    }
        TreeNode* increasingBST(TreeNode* root) {
            TreeNode* prev = NULL , *ans = NULL;
        inorder(root , prev , ans);
            return ans;
    }
};