class Solution {
public:
    bool solve(TreeNode* p, TreeNode* q)
    {
        if(!p and !q)
            return true;
        else if(p and !q)
            return false;
        else if(!p and q)
            return false;
        else if(p->val==q->val)
            return solve(p->left,q->left) and solve(p->right,q->right);
        else
            return false;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return solve(p,q);
    }
};
