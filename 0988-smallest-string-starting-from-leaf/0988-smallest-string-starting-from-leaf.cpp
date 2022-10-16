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
    void solve(TreeNode* root , string s, string& ans)
    {
        if(!root)
            return;
        if(!root -> left and !root -> right)
        {
            string temp = s;
            char ch = root -> val + 'a';
            temp += ch;
            reverse(temp.begin() , temp.end());
            if(ans == "" or ans > temp)
                ans = temp;
        }
        char ch = root -> val + 'a';
        solve(root -> left , s + ch , ans);
        solve(root -> right , s + ch , ans);
    }
    string smallestFromLeaf(TreeNode* root) {
        string ans = "" , s = "";
        solve(root , s , ans);
        return ans;
    }
};