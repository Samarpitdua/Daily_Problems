/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        int ct = 0;
        ListNode *slow = head , *fast = head ;
        ListNode* cty=head;
        if(!head->next)
            return;
        while(cty)
        {
            ct++;
            cty=cty->next;
        }
        while( fast -> next != NULL and fast -> next -> next != NULL)
        {
            
            slow = slow ->next;
            fast = fast-> next ->next;
        }
        ListNode * ptr = slow -> next , *prev = NULL;
       
        while ( ptr)
        {
            ListNode* temp = ptr -> next ;
            ptr -> next = prev;
            prev = ptr ;
            ptr = temp;
        }
       
        cout<<endl;
        
        slow->next=prev;

        ListNode* temp2=head, *temp=head;
    
        slow=slow->next;
        temp=temp->next;
        int p=0;
        //cout<<slow->val<<" "<<temp2->val<<" "<<slow->next->val<<" ";
        while(slow)
        {
            
            if(p==0)
            {
                temp2 -> next = slow ,p=1,temp2=temp2->next,slow=slow->next;
            }
            else
            {
                p = 0,temp2->next=temp,temp2=temp2->next,temp=temp->next;   
            
            }
        }
        if(ct%2)
        {
            temp2->next=temp,temp2=temp2->next,temp=temp->next; 
        }
         temp2->next=NULL;
    }
};
