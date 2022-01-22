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
    ListNode* swapPairs(ListNode* head) {
        if(!head or !head->next)
            return head;
        ListNode* prev , *temp=head;
        int p = -1;
        
        while(1)
        {
            if(p == -1)
            {
                ListNode* temp2 = temp->next;
                temp -> next = temp2->next;
                temp2 -> next = temp;
                prev = temp;
                head = temp2;
                temp = temp -> next;
                p=1;
                
            }
            if(temp and temp->next)
            {
                ListNode* temp2 = temp->next;
                temp -> next = temp2 -> next;
                temp2 -> next = temp;
                prev -> next = temp2;
                prev = temp;
                temp = temp -> next;
                
                
            }
            else
            {
                break;
            }
        }
        return head;
        
    }
};