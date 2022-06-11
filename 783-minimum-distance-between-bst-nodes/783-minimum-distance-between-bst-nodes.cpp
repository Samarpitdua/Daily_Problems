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
    void inorder(int& mini , int& vp , TreeNode* root){
        if(!root)
            return ;
        if(root -> left)
        {
            inorder(mini , vp , root -> left);
        }
        if(vp == -1)
        {
            vp = root -> val;
        }
        else
        {
            mini = min(mini , abs(vp - root -> val));
            vp = root -> val;
        }
        if(root -> right)
            inorder(mini , vp , root -> right);
    }
    int minDiffInBST(TreeNode* root) {
        int val = -1 , mini = INT_MAX;
        inorder(mini , val , root);
        return mini;
    }
};