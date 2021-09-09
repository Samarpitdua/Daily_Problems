class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>mp;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            auto h=q.front();
            q.pop();
            auto node=h.first;
            mp[h.second.first][h.second.second].insert(node->val);
            if(h.first->left)
            {
                q.push({h.first->left,{h.second.first-1,h.second.second+1}});
            }
            if(h.first->right)
            {
                q.push({h.first->right,{h.second.first+1,h.second.second+1}});
            }
        }
        vector<vector<int>>ans;
        for(auto x:mp)
        {
            vector<int>temp;
            for(auto y:x.second)
            {
                temp.insert(temp.end(),y.second.begin(),y.second.end());
            }
            ans.push_back(temp);
            
        }
        return ans;
    }
};
