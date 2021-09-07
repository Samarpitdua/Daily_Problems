
class Solution {
public:
    void solve(TreeNode* root,int level,vector<int>& v)
    {
        if(!root)
            return;
        if(v.size()==level)
            v.push_back(root->val);
         if(root->right)
             solve(root->right,level+1,v);
        if(root->left)
            solve(root->left,level+1,v);
       
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>v;
        if(!root)
            return v;
        solve(root,0,v);      
        return v;
        
    }
};
