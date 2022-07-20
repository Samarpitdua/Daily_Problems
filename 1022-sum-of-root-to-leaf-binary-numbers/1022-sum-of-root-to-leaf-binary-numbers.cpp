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
    int sol(string &y){
        int ans = 0 , ct = 0 , n = y.size();
        for(int i = n - 1 ; i >= 0 ;i--)
        {
            int bit = y[i] - '0';
            if(bit)
                ans += pow(2 , ct);
            ct++;
        }
        return ans;
    }
    void solve(TreeNode* root , string temp , int& ans){
        if(!root -> left and !root -> right){
            temp += to_string(root -> val);
            int sum = sol(temp);
            // cout<<sum<<" ";
            ans += sum;
        }
        if(root -> left)
            solve(root -> left , temp + to_string(root -> val) , ans);
        if(root -> right)
            solve(root -> right , temp + to_string(root -> val) , ans);
    }
    int sumRootToLeaf(TreeNode* root) {
        int  ans = 0;
        string temp = "";
        solve(root , temp , ans);
        return ans;
    }
};