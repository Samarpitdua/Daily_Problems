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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* cur = root;
        while(cur)
        {
            if(!cur -> left)
            {
                ans.push_back(cur -> val);
                cur = cur -> right;
            }
            else
            {
                TreeNode* temp = cur;
                cur = cur -> left;
                while(cur -> right and cur -> right != temp)
                {
                    cur = cur -> right;
                }
                if(cur -> right == NULL)
                {
                    cur -> right = temp;
                    cur = temp -> left;
                }
                else
                {
                    cur -> right = NULL;
                    ans.push_back(temp -> val);
                    cur = temp -> right;
                }
            }
        }
        return ans;
    }
};