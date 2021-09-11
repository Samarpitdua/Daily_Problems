class Solution {
public:
    TreeNode* solve(vector<int>& postorder,int poststart,int postend,vector<int>& inorder,int instart,int inend,map<int,int>& mp)
    {
        if(instart>inend or poststart>postend)
            return NULL;
        TreeNode *root=new TreeNode(postorder[postend]);
        int n=mp[root->val];
        int prev=n-instart;
        root->left=solve(postorder,poststart,poststart+prev-1,inorder,instart,n-1,mp);
        root->right=solve(postorder,poststart+prev,postend-1,inorder,n+1,inend,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        TreeNode *root=solve(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,mp);
        return root;
    }
};
