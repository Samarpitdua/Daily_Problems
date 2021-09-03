class Solution {
public:
    void solve(TreeNode* root,vector<int>& v,int ok)
    {
        if(!root)
            return;
        if(ok==1 and root->left==NULL and root->right==NULL)
            v.push_back(root->val);
        if(root->left)solve(root->left,v,1);
        if(root->right)solve(root->right,v,0);
        
    }
    int sumOfLeftLeaves(TreeNode* root) {
        vector<int>v;
        if(root->left==NULL and root->right==NULL)
            return 0;
        int sum=0;
        solve(root,v,0);
        for(auto x:v)
            sum+=x;
        return sum;
        
    }
};
