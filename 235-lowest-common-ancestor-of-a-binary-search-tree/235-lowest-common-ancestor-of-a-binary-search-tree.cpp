/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p -> val > q -> val)
            swap(p , q);
       if(!root)
           return root;
        if(root -> val >= p -> val and root -> val <= q -> val)
            return root;
        else if(root -> val >= p -> val and root -> val >= q -> val)
            return lowestCommonAncestor(root -> left , p , q);
        else
            return lowestCommonAncestor(root -> right , p , q);
        
    }
    
    
    
    
    
    
    
    
    
    
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(p->val<root->val and q->val<root->val)
            return solve(root->left,p,q);
        else if(p->val>root->val and q->val>root->val)
            return solve(root->right,p,q);
        else
            return root;
    }
};