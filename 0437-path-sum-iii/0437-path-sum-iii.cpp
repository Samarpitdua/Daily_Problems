/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    void solve(TreeNode* root , long long int sum){
        if(!root)
        {
            return;
        }
        if(root -> val == sum)
            ans++;
        solve(root -> left , sum - root -> val);
        solve(root -> right , sum - root -> val);
        
    }
    int pathSum(TreeNode* root, int sum) {
        if(!root)
            return 0;
        solve(root , sum);
        pathSum(root -> left , sum);
        pathSum(root -> right , sum);
        
        return ans;
    }
};