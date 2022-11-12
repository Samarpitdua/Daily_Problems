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
    set<TreeNode*> set;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        for(TreeNode* node : nodes)
            set.insert(node);
        return helper(root);
    }
    
    TreeNode* helper(TreeNode* root) {
        if(root == NULL)
            return root;
        TreeNode* left = helper(root->left);
        TreeNode* right = helper(root->right);
        if(left!= NULL && right != NULL)
            return root;
        if(set.find(root) != set.end())
            return root;
        return left!=NULL ? left : right;
    }
};