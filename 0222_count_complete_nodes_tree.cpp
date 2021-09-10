class Solution {
public:
    int calculateLeft(TreeNode* root)
    {
        if(!root)
            return 0;
        int ct=0;
        while(root)
        {
            ct++;
            root=root->left;
        }
        return ct;
    }
    int calculateRight(TreeNode* root)
    {
        if(!root)
            return 0;
        int ct=0;
        while(root)
        {
            ct++;
            root=root->right;
        } 
        return ct;
    }
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        int lt=calculateLeft(root);
        int rt=calculateRight(root);
        if(lt==rt)
            return ((1<<lt)-1);
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};
