class Solution {
public:
    void inorder(TreeNode* root,vector<int>& v)
    {
        if(!root)
            return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        vector<int>v;
        inorder(root,v);
        for(int i=0;i<v.size()-1;i++)
        {
            if(v[i]<v[i+1])
                continue;
            else
                return false;
        }
        return true;
    }
};
