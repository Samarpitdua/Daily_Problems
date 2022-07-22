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
    ListNode* partition(ListNode* head, int x) {
        if(!head)
            return head;
        ListNode* temp = NULL,*temp2 = NULL;
        ListNode* ans1 = new ListNode(0) , *ans2 =  new ListNode(0);
        while(head)
        {
            if(head -> val < x){
                if(!temp)
                {
                    temp = head;
                    ans1 -> next = temp;
                    head = head -> next;
                    continue;
                }
                temp -> next = head;
                temp = temp -> next;
                head = head -> next;
            }
            else{
                if(!temp2)
                {
                    temp2 = head;
                    ans2 -> next = temp2;
                    head = head -> next;
                    continue;
                }
                temp2 -> next = head;
                temp2 = temp2 -> next;
                head = head -> next;
            }
            
        }
        if(!temp)
            return ans2 -> next;
        if(!temp2)
            return ans1 -> next;
        else
        {
            ans1 = ans1 -> next;
            ans2 = ans2 -> next;
            temp -> next = ans2;
            temp2 -> next = NULL;
            return ans1;
        }
        return NULL;
    }
};