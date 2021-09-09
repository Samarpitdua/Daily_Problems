class Solution {
public:
    void inorder(TreeNode* root,int k,int& i,int& ans)
    {
        if(!root)
            return ;
        inorder(root->left,k,i,ans);
        i++;
        if(i==k)
            ans=root->val;
        inorder(root->right,k,i,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int i=0;
        int ans=INT_MAX;
        inorder(root,k,i,ans);
        return ans;
    }
};
