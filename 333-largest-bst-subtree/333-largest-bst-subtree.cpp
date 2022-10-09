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
struct bst
{
    bool isBST;
    int maxi;
    int mini;
    int sz;
};
class Solution {
public:
    bst largestBST(TreeNode* root)
    {
        if(!root)
        {
            bst b = {true , INT_MIN , INT_MAX , 0};
            return b;
        }
        bst l = largestBST(root -> left);
        bst r = largestBST(root -> right);
        if(l.isBST and r.isBST and r.mini > root -> val and l.maxi < root -> val)
        {
            bst b = {true , max(root -> val , r.maxi) , min(root -> val , l.mini) , 1 + l.sz + r.sz};
            return b;
        }
        return {false , -1 , -1 , max(l.sz , r.sz)};
    }
    int largestBSTSubtree(TreeNode* root) {
        bst b = largestBST(root);
        return b.sz;
    }
};