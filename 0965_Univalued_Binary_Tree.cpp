class Solution {
public:
    void preorder(TreeNode* root,set<int>& s)
    {
        if(!root)return;
        s.insert(root->val);
        preorder(root->right,s);
        preorder(root->left,s);
        
    }
    bool isUnivalTree(TreeNode* root) {
        set<int>st;
        preorder(root,st);
        if(st.size()==1)
            return true;
        return false;
        
    }
};
