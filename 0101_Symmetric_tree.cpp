class Solution {
public:
    bool check(TreeNode* p,TreeNode* q)
    {
        if(!p and !q)
            return true;
        if(!p or !q)
            return false;
        if(p->val!=q->val)
            return false;
        return(check(p->left,q->right) and check(p->right,q->left));
    }
    bool isSymmetric(TreeNode* root) {
        if(root->left==NULL and root->right==NULL)
            return true;
       return check(root->left,root->right);
        
    }
};
