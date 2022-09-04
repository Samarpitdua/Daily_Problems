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
    void goleft(TreeNode* root , vector<int>& ans , map<TreeNode* , int>& mp){
        while(root)
        {
            if(!mp[root])
                ans.push_back(root -> val) , mp[root] = 1;
            if(root -> left)
                root = root -> left;
            else
            {
                root = root -> right;
            }
        }
    }
    void goright(TreeNode* root , vector<int>& ans , map<TreeNode* , int>& mp){
        while(root)
        {
            if(!mp[root])
                ans.push_back(root -> val) , mp[root] = 1;
            if(root -> right)
                root = root -> right;
            else
                root = root -> left;
        }
        reverse(ans.begin() , ans.end());
    }
    void inorder(TreeNode* root, vector<int>& ans , map<TreeNode* , int>& mp){
        if(!root)
            return;
        inorder(root -> left , ans ,mp);
        if(!root -> left and !root -> right and !mp[root])
            ans.push_back(root -> val) , mp[root] = 1;
        inorder(root -> right , ans , mp);
    }
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> ans , temp;
        map<TreeNode* , int> mp;
        ans.push_back(root -> val);
        mp[root] = 1;
        goleft(root -> left, ans , mp);
        inorder(root , ans , mp);
        goright(root -> right, temp , mp);
        for(auto x : temp)
            ans.push_back(x);
        return ans;
    }
};