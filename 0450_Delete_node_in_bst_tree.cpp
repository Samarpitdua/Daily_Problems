class Solution {
public:
    TreeNode *findleftmost(TreeNode* root)
    {
        if(!root->right)
            return root;
        return findleftmost(root->right);
    }
    TreeNode* helper(TreeNode *root)
    {
        if(!root->left)return root->right;
        if(!root->right)return root->left;
        TreeNode* leftyy=findleftmost(root->left);
        leftyy->right=root->right;
        return root->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return NULL;
        if(root->val==key)
            return helper(root);
            
        TreeNode *dummy=root;
        while(root){
        if(root->val>key)
        {
            if(root->left and root->left->val==key)
            {
                root->left=helper(root->left);
                break;
            }
            else
                root=root->left;
        }
        else if(root->val<key)
        {
            if(root->right and root->right->val==key)
            {
                root->right=helper(root->right);
                break;
            }
            else
                root=root->right;
        }
        }
        return dummy;
    }
};
