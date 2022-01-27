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
    void inorder(TreeNode* root,int k,int& i,int& ans)
    {
        if(!root)
            return ;
        inorder(root -> left, k , i ,ans);
        i++;
        if(i > k)
            return;
        if(i == k)
            ans = root -> val;
        
        inorder(root -> right , k , i , ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int i = 0;
        int ans = INT_MAX;
        inorder(root , k , i , ans);
        return ans;
    }
};