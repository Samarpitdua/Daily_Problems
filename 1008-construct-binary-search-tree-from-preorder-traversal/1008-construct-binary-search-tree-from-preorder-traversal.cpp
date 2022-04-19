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
    TreeNode* constTree(vector<int>& pre,int& mini,int& maxi,int& ptr)
    {
        if(ptr >= pre.size())
            return NULL;
        if(pre[ptr] < mini or pre[ptr] > maxi)
            return NULL;
        TreeNode* root = new TreeNode(pre[ptr]);
        int x = pre[ptr];
        ptr++;
        root -> left = constTree(pre , mini , x , ptr);
        root -> right = constTree(pre , x , maxi , ptr);
        return root;
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int ptr = 0;
        int mini = INT_MIN , maxi = INT_MAX;
        return constTree(preorder , mini , maxi , ptr);
    }
};