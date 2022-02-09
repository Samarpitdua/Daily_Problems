/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        stack<Node* > st;
        Node* root = head;
        if(! head)
            return head;
        while(head or !st.empty())
        {
            if(head and head -> child)
            {
                if(head -> next)
                    st.push(head -> next);
                head -> next = head -> child;
                head -> child = NULL;
                Node* temp2 = head;
                head = head -> next;
                if(head)
                head -> prev = temp2;
            }
            else
            {
                
                if(head and head -> next)
                {
                    head -> child = NULL;
                    head = head -> next;
                }
                else if(!st.empty())
                {
                    Node* temp = st.top();
                    head -> next = st.top();
                    head -> child = NULL;
                    st.pop();
                     Node* temp2 = head;
                    head = head -> next;
                    if(head)
                    head -> prev = temp2;
                }
                else
                {
                    if(head){
                    head -> child = NULL;
                    head = head -> next;
                    }
                    else
                        break;
                }
            
            }
            // cout<<head -> val<<" ";
        }
        return root;
    }
};