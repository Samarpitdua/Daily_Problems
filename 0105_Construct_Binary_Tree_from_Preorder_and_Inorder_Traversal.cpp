class Solution {
public:
    TreeNode* solve(vector<int>& preorder,int prestart,int preend,vector<int>& inorder,int instart,int inend,map<int,int>& mp)
    {
        if(prestart>preend or instart>inend)
            return NULL;
        TreeNode *root=new TreeNode(preorder[prestart]);
        int n=mp[root->val];
        int opleft=n-instart;
        root->left=solve(preorder,prestart+1,prestart+opleft,inorder,instart,n-1,mp);
        root->right=solve(preorder,prestart+opleft+1,preend,inorder,n+1,inend,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        TreeNode *root=solve(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
        return root;
    }
};
