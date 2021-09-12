
class Solution {
public:
    
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        int ans = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root,0});
       
        while(!q.empty())
        {     
            int mmin=q.front().second;
            int first,last;
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                TreeNode* node=q.front().first;     
                int cur=q.front().second-mmin;
                 q.pop();
                if(i==0)first=cur;
                if(i==sz-1)last=cur;
                if(node->left)q.push({node->left,(cur*2)+1});
                if(node->right)q.push({node->right,cur*2+2});
            }   
            ans=max(ans,last-first+1);
        }
        return ans;    
    }   
};
