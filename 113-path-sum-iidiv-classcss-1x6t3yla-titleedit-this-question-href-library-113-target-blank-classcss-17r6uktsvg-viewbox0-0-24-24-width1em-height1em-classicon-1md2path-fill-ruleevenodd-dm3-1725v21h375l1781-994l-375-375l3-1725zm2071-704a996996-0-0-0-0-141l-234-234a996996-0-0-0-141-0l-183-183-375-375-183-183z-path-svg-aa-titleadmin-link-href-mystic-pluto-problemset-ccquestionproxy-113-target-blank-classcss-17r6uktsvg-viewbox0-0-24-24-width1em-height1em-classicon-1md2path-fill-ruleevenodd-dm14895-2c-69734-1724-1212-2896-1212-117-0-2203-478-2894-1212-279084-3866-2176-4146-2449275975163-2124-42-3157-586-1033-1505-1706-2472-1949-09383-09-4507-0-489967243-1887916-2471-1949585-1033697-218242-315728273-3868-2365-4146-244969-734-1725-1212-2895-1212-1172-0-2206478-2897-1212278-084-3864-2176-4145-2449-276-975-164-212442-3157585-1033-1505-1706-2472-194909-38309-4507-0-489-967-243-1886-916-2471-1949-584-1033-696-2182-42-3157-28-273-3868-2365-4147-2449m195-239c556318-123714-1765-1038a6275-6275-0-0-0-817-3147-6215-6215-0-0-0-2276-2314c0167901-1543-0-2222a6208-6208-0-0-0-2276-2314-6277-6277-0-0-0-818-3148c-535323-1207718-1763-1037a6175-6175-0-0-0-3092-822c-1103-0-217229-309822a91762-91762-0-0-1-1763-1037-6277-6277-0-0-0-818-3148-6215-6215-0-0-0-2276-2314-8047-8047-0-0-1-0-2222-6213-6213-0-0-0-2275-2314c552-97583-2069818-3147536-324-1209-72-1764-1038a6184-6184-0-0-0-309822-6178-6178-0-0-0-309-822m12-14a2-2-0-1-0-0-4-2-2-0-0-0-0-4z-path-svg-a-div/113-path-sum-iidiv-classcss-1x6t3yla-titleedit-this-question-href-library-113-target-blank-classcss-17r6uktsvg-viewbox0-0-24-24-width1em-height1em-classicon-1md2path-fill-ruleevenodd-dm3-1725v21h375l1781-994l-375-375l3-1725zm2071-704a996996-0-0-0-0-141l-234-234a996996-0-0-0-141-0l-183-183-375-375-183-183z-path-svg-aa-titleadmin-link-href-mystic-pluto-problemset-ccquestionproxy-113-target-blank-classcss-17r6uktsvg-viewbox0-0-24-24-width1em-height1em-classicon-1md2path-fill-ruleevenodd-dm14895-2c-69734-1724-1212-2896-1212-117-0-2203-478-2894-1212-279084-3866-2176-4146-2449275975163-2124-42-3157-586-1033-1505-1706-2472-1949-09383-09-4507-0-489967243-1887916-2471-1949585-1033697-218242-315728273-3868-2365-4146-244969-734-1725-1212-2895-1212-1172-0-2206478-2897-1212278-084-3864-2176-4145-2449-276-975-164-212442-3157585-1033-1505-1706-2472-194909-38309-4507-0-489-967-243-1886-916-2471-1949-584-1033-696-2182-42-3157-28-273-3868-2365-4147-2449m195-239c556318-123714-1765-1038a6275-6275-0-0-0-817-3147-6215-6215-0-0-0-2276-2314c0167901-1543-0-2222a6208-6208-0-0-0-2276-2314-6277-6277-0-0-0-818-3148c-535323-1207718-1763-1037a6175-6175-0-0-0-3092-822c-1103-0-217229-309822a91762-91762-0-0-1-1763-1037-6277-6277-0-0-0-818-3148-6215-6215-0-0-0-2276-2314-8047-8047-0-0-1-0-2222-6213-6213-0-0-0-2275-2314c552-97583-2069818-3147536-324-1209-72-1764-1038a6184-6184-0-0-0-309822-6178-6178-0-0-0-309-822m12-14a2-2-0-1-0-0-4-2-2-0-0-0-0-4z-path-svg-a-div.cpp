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
    void solve(TreeNode* root , int targetSum ,vector<vector<int>>& ans , int sum , vector<int> temp )
    {
        if((!root -> left and !root -> right))
        {
            sum += root -> val;
            temp.push_back(root -> val);
            if(sum == targetSum)
            {
                ans.push_back(temp);
            }
            return;
        }
        temp.push_back(root -> val);
        if(root -> left)
            solve(root -> left , targetSum , ans , sum + root -> val , temp);
        if(root -> right)
        solve(root -> right , targetSum , ans , sum + root -> val , temp);
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        vector<vector<int>> ans;
        vector<int> temp;
        if(!root)
            return ans;
        solve(root , targetSum , ans , 0 , temp);
        return ans;
    }
};