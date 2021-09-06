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
    void solve(TreeNode* root,map<int,vector<int>>& mp,int level)
    {
        if(!root)
            return;
        mp[level].push_back(root->val);
        if(root->left)
            solve(root->left,mp,level+1);
        if(root->right)
            solve(root->right,mp,level+1);
    }
    int maxLevelSum(TreeNode* root) {
        map<int,vector<int>>mp;
        if(!root)
            return 0;
        solve(root,mp,1);
        int maxi=INT_MIN;
        int ans=1;
        for(auto x:mp)
        {
            int sum=0;
            for(auto y:x.second)
            {
                sum+=y;
            }
            if(sum>maxi)
                ans=x.first,maxi=sum;
        }
        return ans;
    }
};
