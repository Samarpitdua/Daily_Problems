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
    
    int widthOfBinaryTree(TreeNode* root) {
        long long int ans = 0;
        queue<pair<TreeNode*, long long int>> q;
        q.push({root , 0});
        while(!q.empty())
        {
            long long int sz = q.size();
            long long int mini = q.front().second;
            long long int first , last;
            for(int i = 0 ; i < sz ; i++)
            {
                TreeNode* temp = q.front().first;
                long long int val = q.front().second - mini;
                
                q.pop();
                
                if(i == 0)
                    first = val;
                
                if(i == sz - 1)
                    last = val;
                
                if(temp -> left)
                {
                    q.push({temp -> left , 2 * val + 1});
                }
                if(temp -> right)
                {
                    q.push({temp -> right , 2 * val + 2});
                }
            }
            ans = max(ans , last - first + 1);
        }
        return int(ans);
    }
       
     
};