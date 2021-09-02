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
    void find(TreeNode* root,vector<int>& v)
    {
        if(root==NULL)
            return;
        find(root->left,v);
        find(root->right,v);
        v.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>v;
        stack<TreeNode*>st1,st2;
        if(!root)
            return v;
        st1.push(root);
        while(1)
        {
            if(st1.empty())
                break;
            TreeNode*temp=st1.top();
            st1.pop();
            st2.push(temp);
            if(temp->left!=NULL)st1.push(temp->left);
            if(temp->right!=NULL)st1.push(temp->right);
        }
        while(!st2.empty())
        {
            v.push_back(st2.top()->val);
            st2.pop();
        }
        return v;
    }
};
