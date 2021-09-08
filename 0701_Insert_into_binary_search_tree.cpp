class Solution {
public:
    TreeNode* insertIntoBSTs(TreeNode* root, int val)
    {
        if(!root)
        {
            root=new TreeNode(val);
            return root;
        }
        else
        {
            if(root->val<val)
            {
                root->right=insertIntoBST(root->right,val);
            }
            else
            {
                root->left=insertIntoBST(root->left,val);
            }
        }
        return root;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return insertIntoBSTs(root,val);
        //return root;
        
    }
};
