class Solution {
public:
    struct bst{
        bool isBST;
        int maxi;
        int mini;
        int sum;
    };
    
    int ans = 0;
    bst solve(TreeNode* root) {

      if(!root)
      {
          bst b = {true , INT_MIN , INT_MAX , 0};
          return b;
      }
        
        bst b;
        bst l = solve(root -> left);
        bst r = solve(root -> right);
        if(l.isBST and r.isBST and root -> val > l.maxi and root -> val < r.mini)
        {
            b = {true , max(root -> val , r.maxi) , min(root -> val , l.mini) , l.sum + r.sum + root -> val};
            ans = max(ans , b.sum);
            
        }
        else
            b = {false , -1 , -1 , 0};
        
        return b;
    }
    
    
    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};