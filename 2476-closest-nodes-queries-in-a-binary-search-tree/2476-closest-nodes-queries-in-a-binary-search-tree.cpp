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
    void inorder(TreeNode* root , vector<int>& v){
        if(!root)
            return;
        if(root -> left)
            inorder(root -> left , v);
        v.push_back(root -> val);
        if(root -> right)
            inorder(root -> right , v);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> v;
        
        inorder(root , v);
        int n = v.size();
        sort(v.begin() , v.end());
        vector<vector<int>> ans;
        for(auto x : queries)
        {
            vector<int> temp;
            int mini = lower_bound(v.begin() , v.end() , x) - v.begin();
            cout<<mini<<" ";
            if(x < v[0])
                temp.push_back(-1);
            else if(mini >= n)
                temp.push_back(v[mini - 1]);
            else if(v[mini] == x)
                temp.push_back(x);
            else
                temp.push_back(v[mini - 1]);
            
            int maxi = upper_bound(v.begin() , v.end() , x) - v.begin();
            if(x <= v[0])
                temp.push_back(v[0]);
            else if(x > v[n - 1])
                temp.push_back(-1);
            else if(x == v[n - 1])
                temp.push_back(x);
            else if(x == v[maxi - 1])
                temp.push_back(x);
            else
                temp.push_back(v[maxi]);
            ans.push_back(temp);
        }
        return ans;
        
    }
};