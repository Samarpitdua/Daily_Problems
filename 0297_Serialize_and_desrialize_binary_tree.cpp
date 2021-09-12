class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        if(!root)
            return "";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* cur=q.front();
            q.pop();
            if(cur==NULL)s+="#,";
            else
                s+=to_string(cur->val),s+=',';
            if(cur)
            {
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)return NULL;
        stringstream s(data);
        string ans;
        getline(s,ans,',');
        TreeNode* root=new TreeNode(stoi(ans));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode *node=q.front();
            q.pop();
            getline(s,ans,',');
            if(ans=="#")
                node->left=NULL;
            else
            {
                TreeNode* leftNode=new TreeNode(stoi(ans));
                node->left=leftNode;
                q.push(leftNode);
            }
            getline(s,ans,',');
            if(ans=="#")
                node->right=NULL;
            else
            {
                TreeNode* rightNode=new TreeNode (stoi(ans));
                node->right=rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

