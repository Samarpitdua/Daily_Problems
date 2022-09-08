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
    void solve(TreeNode* root , double target , double& ans , int& ct){
        if(!root)
            return;
        if(root -> val == target)
        {
            ct = root -> val;
            ans = 0;
            return;
        }
        if(root -> val > target)
        {
            if(ans > abs(target - root -> val))
            ans = abs(target - root -> val) , ct = root -> val;
            cout<<ans<<" ";
            solve(root -> left , target , ans , ct);
        }
        else
        {
            
            if(ans > abs(target - root -> val))
            ans = abs(target - root -> val) , ct = root -> val;
            solve(root -> right , target , ans , ct);
        }
    }
    int closestValue(TreeNode* root, double target) {
        double ans = 1000000.0;
        int ct = 0;
        // cout<<abs(target - 4)<<" ";
        solve(root , target , ans , ct);
        return ct;
    }
};