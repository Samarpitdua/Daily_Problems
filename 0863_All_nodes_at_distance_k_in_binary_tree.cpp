class Solution {
public:
    void markParents(TreeNode *root,map<TreeNode*,TreeNode*>& mp)
    {
        if(!root)
            return;
        if(root->left)
        {
            mp[root->left]=root;
            markParents(root->left,mp);
        }
        if(root->right)
        {
            mp[root->right]=root;
            markParents(root->right,mp);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*>mp;
        markParents(root,mp);
        map<TreeNode*,bool>vis;
        queue<TreeNode*>q;
        int ct=0;
        vis[target]=true;
        q.push(target);
        vector<int>ans;
        while(1)
        {
            if(ct==k)
                break;
            ct++;
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                TreeNode *cur=q.front();
                q.pop();
                if(cur->left and !vis[cur->left])
                {
                    q.push(cur->left);
                    vis[cur->left]=true;
                }
                if(cur->right and !vis[cur->right])
                {
                    q.push(cur->right);
                    vis[cur->right]=true;
                }
                if(mp[cur] and !vis[mp[cur]])
                {
                    q.push(mp[cur]);
                    vis[mp[cur]]=true;
                }
            }
        }
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};
