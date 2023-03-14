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
    void solve(TreeNode* root , string s , vector<string>& ans)
    {
        if(!root -> left and !root -> right)
        {
            s+= to_string(root -> val);
            ans.push_back(s);
            return;
        }
        else
        {
            s += to_string(root -> val);
            if(root -> left)
            solve(root->left ,s ,ans);
            if(root -> right)
            solve(root -> right, s ,ans);
            
        }
    }
    int sumNumbers(TreeNode* root) {
        vector<string> ans;
        string s = "";
        int ans2 = 0;
        solve(root , s , ans);
        for(auto x: ans)
        {
            ans2 += stoi(x);
        }
        return ans2;
    }
};