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
    TreeNode* createBinaryTree(vector<vector<int>>& des) {
        map<int , TreeNode*> mp;
        unordered_map<int , int> mp2 , mp3;
        for(auto x : des)
        {
            mp2[x[0]] = 1;
            mp3[x[1]] = 1;
            
            int par = x[0] , child = x[1] , loo = x[2];
            TreeNode* newnode;
            if(mp.find(child) != mp.end())
            {
                newnode = mp[child];
            }
            else
                newnode = new TreeNode(child);
            
            if(mp[par])
            {
                if(loo)
                {
                    mp[par] -> left = newnode;
                }
                else
                    mp[par] -> right = newnode;
            }
            else
            {
                TreeNode* newpar = new TreeNode(x[0]);
                if(loo)
                {
                    newpar -> left = newnode;
                }
                else
                    newpar -> right = newnode;
                mp[x[0]] = newpar;
            }
             mp[child] = newnode;
        }
        for(auto x : mp2)
        {
            if(mp3.find(x.first) == mp3.end())
            {
                // cout<<x.first<<" ";
                return mp[x.first];
            }
        }
        return NULL;
    }
};