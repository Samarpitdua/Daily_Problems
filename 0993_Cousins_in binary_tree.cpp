class Solution {
public:
    void findDepth(TreeNode* root,map<int,int>& mp,int level,vector<int>& par)
    {
        if(!root)
            return;
        mp[root->val]=level;
        if(root->left)par[root->left->val]=root->val,findDepth(root->left,mp,level+1,par);
        if(root->right)par[root->right->val]=root->val,findDepth(root->right,mp,level+1,par);
        
    }
    bool isCousins(TreeNode* root, int x, int y) {
        map<int,int>mp;
        vector<int>par(105,-1);
        findDepth(root,mp,0,par);
        if(mp[x]==mp[y] and par[x]!=par[y])
            return true;
        else 
            return false;
    }
};
