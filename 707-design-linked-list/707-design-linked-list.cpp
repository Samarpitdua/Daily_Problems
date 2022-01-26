struct Node
{
    int val;
    int sz = 0;
    Node* next;
           Node(int val)
           {
               this -> val = val;
               next = NULL;
           }
};
class MyLinkedList {
public:
    int sz = 0;
    Node* head = new Node(0);
    MyLinkedList() {
        
    }
    
    int get(int index) {
        int ct = -1;
        if(index >= sz)
            return -1;
        Node* temp = head;
        while(ct != index)
        {
            temp = temp -> next;
            ct++;
        }
        return temp->val;
        
    }
    
    void addAtHead(int val) {
        Node* temp = head -> next;
        head -> next = new Node(val);
        head -> next -> next = temp;
        sz++;
    }
    
    void addAtTail(int val) {
        Node* temp = head;
        while(temp -> next)
        {
            temp = temp -> next;
        }
        temp -> next = new Node(val);
        sz++;
    }
    
    void addAtIndex(int index, int val) {
        //cout<<sz<<" ";
        int ct = 0;
        if(index > sz)
            return ;
        Node* temp = head;
        while(ct != index)
        {
            temp = temp -> next;
            ct++;
        }
        Node* temp2 = temp -> next;
        temp -> next = new Node(val);
        temp -> next -> next = temp2;
       // cout<<val<<" "<<temp->val<<" "<<temp->next->val<<"\n";
        sz++;
    }
    
    void deleteAtIndex(int index) {
        int ct = 0;
        if(index >= sz)
            return ;
        Node* temp = head;
        while(ct != index)
        {
            temp = temp -> next;
            ct++;
        }
        temp -> next = temp -> next -> next;
        sz--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */