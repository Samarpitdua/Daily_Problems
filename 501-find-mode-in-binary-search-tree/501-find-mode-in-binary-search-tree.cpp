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
    void preorder(TreeNode* root , unordered_map<int , int>& ans)
    {
        if(!root)
            return;
        ans[root -> val]++;
        preorder(root -> left , ans);
        preorder(root -> right , ans);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        unordered_map<int , int>mp;
        preorder(root , mp);
        int maxi = INT_MIN;
        for(auto x : mp)
        {
            if(x.second > maxi)
            {
                maxi = x.second;
            }
        }
        for(auto x : mp)
        {
            if(x.second == maxi)
            {
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};