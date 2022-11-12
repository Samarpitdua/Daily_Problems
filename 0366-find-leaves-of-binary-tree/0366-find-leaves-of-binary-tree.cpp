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
    vector<vector<int>> ans;
    int h;
    vector<vector<int>> findLeaves(TreeNode* root) {
        h = getHeight(root); // Get maximum height 
        ans.resize(h); // Initialize array with size if height
        dfs(root); // Call the actual function
        return ans;
    }
    
    int getHeight(TreeNode* root)
    {
        return root ? 1 + max(getHeight(root -> left), getHeight(root -> right)) : 0;
    }
    
    int dfs(TreeNode* root)
    {
        if(!root)
            return 0;
        int temp = 1+max(dfs(root->left), dfs(root->right)); // Get height of the element
        ans[temp-1].push_back(root->val); // Push the element at the position = height of element.
        return temp; 
    }
};