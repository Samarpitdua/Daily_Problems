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
    void solve(TreeNode* root , string t ,vector<string>& ans)
    {
        if(( !root -> left and !root -> right))
        {
            t += to_string(root -> val);
            ans.push_back(t);
            return;
        }
        t += to_string(root -> val);
        t += "->";
        if(root -> left)
            solve(root -> left , t , ans);
        if(root -> right)
            solve(root -> right , t , ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string t = "";
        solve(root , t, ans);
        return ans;
    }
};