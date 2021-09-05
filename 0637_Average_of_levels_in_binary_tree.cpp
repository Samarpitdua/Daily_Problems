class Solution {
public:
    void levelOrder(TreeNode* root,vector<vector<int>>& v)
    {
        vector<int>ans;
        if(!root)
            return;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            ans.clear();
            int sz=q.size();
            while(sz--)
            {
                TreeNode* temp=q.front();
                ans.push_back(temp->val);
                q.pop();
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
            v.push_back(ans);
        }
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<vector<int>>v;
        levelOrder(root,v);
        vector<double>ans;
        double sum=0;
        for(auto x:v)
        {
            for(auto y:x)
            {
                sum+=y;
            }
            sum=sum/double(x.size());
            ans.push_back(sum);
            sum=0;
        }
        return ans;
    }
};
