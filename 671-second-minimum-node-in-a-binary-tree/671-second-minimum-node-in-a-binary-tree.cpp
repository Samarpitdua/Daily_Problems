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
    void preorder(TreeNode* root , long long int& mini , long long int& mini2)
    {
        if(!root)
            return;
        if(mini == INT_MAX)
            mini = root -> val;
        else
        {
            if(root -> val < mini)
            {
                mini2 = mini;
                mini = root -> val;
            }
            else if(root -> val > mini)
            {
                if(root -> val < mini2)
                    mini2 = root -> val;
            }
        }
        preorder(root -> left , mini , mini2);
        preorder(root -> right , mini , mini2);
    }
    int findSecondMinimumValue(TreeNode* root) {
        long long int mini = 1e18 , mini2 = 1e18;
        preorder(root , mini , mini2);
        if(mini2 == 1e18)
            return -1;
        return mini2;
    }
};