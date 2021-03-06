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
// Kepp putting left until null.when next function is called pop element from stack and if it has right put it into stack.
//is stack not empty hasnext return true else it will return false;
class BSTIterator {
public:
    stack <TreeNode*> st;
    BSTIterator(TreeNode* root) {
        inorder(root);
    }
    void inorder(TreeNode* root)
    {
        if(!root)
            return;
        while(root)
        {
            st.push(root);
            root = root -> left;
        }
    }
    int next() {
        TreeNode* top = st.top();
        st.pop();
        inorder(top -> right);
        return top -> val;
        
    }
    
    bool hasNext() {
        return (! st.empty());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */