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
    void calculate(TreeNode* root,map<int,vector<int>>& mp,int level)
    {
        if(!root)return ;
        mp[level].push_back(root->val);
        if(root->left)
            calculate(root->left,mp,level+1);
        if(root->right)
            calculate(root->right,mp,level+1);
    }
    int deepestLeavesSum(TreeNode* root) {
        map<int,vector<int>>mp;
        if(!root)
            return 0;
        calculate(root,mp,0);
        int maxi=0;
        
        for(auto x:mp)
        {
            if(x.first>maxi)
                maxi=x.first;
        }
        int sum=0;
        for(auto y:mp[maxi])
            sum+=y;
        return sum;
    }
};