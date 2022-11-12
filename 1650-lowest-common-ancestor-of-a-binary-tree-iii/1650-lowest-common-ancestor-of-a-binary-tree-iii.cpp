/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lca(Node* root , Node* p , Node* q)
    {
        if(!root or root == p or root == q)
            return root;
        Node* l = lca(root -> left , p , q);
        Node* r = lca(root -> right ,p , q);
        if(!l)
            return r;
        if(!r)
            return l;
        return root;
    }
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node* root = p;
        while(root -> parent)
            root = root -> parent;
        return lca(root , p , q);
    }
};