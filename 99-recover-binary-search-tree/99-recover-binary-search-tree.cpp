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
    void inorder(TreeNode* root , TreeNode* &one , TreeNode* &two , TreeNode* &prev)
    {
        if(!root)
            return;
        inorder(root -> left , one , two , prev);
        if(!prev)
            prev = root;
        else
        {
            if(root -> val < prev -> val)
            {
                if(!one)
                    one = prev;
                if(one)
                    two = root;
                // return;
            }
            else
                prev = root;
        }
        inorder(root -> right , one , two , prev);
        
    }
    void recoverTree(TreeNode* root) {
        TreeNode* one = NULL , *two = NULL , *prev = NULL;
        inorder(root , one , two , prev);
        swap(one -> val, two -> val);
        
    }
};