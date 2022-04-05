/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return head;
        Node* root1 = head , *root2 = head;
        //copy of each node is made and connected in order like
        //original1 -> copy1 -> original2 -> copy2 .....
        while(root1)
        {
            root2 = root1 -> next;
            Node* copy = new Node(root1 -> val);
            copy-> next = root2;
            root1 -> next = copy;
            root1 = root2;
        }
        
        //attach random pointers of copy  nodes
        root1 = head;
        while(root1)
        {
            if(root1 -> random)
            {
                root1 -> next -> random = root1 -> random -> next;
            }
            root1 = root1 -> next -> next;
        }
        
        //seperate copy and original
        root1 = head , root2 = head -> next;
        Node* ans = root2;
        while(root2)
        {
            root1 -> next = root2 -> next;
            if(root1 -> next)
                root2 -> next = root1 -> next -> next;
            else
                break;
            root1 = root1 -> next;
            root2 = root2 -> next;
        }
        return ans;
    }
};