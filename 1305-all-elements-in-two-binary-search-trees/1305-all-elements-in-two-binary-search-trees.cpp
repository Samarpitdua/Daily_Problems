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
    void inorder(TreeNode* root , vector<int>& temp1)
    {
        if(!root)
            return;
        inorder(root -> left , temp1);
        temp1.push_back(root -> val);
        inorder(root -> right , temp1);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans , temp1 , temp2;
        inorder(root1 , temp1);
        inorder(root2 , temp2);
        auto i = temp1.begin() , j = temp2.begin();
        for(; i != temp1.end() and j != temp2.end() ;)
        {
            if(*i > *j)
            {
                ans.push_back(*j);
                j++;
            }
            else
            {
                 ans.push_back(*i);
                 i++;
            }
        }
        while(i != temp1.end())
        {
             ans.push_back(*i);
                 i++;
        }
        while(j != temp2.end())
        {
             ans.push_back(*j);
                     j++;
        }
        return ans;
        
    }
};