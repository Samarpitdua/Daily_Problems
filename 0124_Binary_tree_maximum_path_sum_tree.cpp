
class Solution {
public:
    int solve(TreeNode* root,int& maxi)
    {
        if(!root)
            return 0;
        int lt=solve(root->left,maxi);
        int rt=solve(root->right,maxi);
        if(lt<0)
            lt=0;
        if(rt<0)
            rt=0;
        maxi=max(root->val+lt+rt,maxi);
        return root->val+max(lt,rt);
    }
    int maxPathSum(TreeNode* root) {
     int maxi=INT_MIN;   
        int a=solve(root,maxi);
        return maxi;
    }
};
