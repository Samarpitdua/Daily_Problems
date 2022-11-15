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

    int countNodes(TreeNode* root) {
        if(! root)
            return 0;
        TreeNode* temp = root;
        int ct = 0 , ct2 = 0;
        while(temp -> left)
        {
            ct++;
            temp = temp -> left;
        }
        temp = root;
        while(temp -> right)
        {
            ct2++;
            temp = temp -> right;
        }
        if(ct == ct2) 
            return  pow(2 , ct + 1) - 1;
        
        return 1 + countNodes(root -> left) + countNodes(root -> right);
    }
};