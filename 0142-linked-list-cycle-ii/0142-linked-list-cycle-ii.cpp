/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head , *slow = head;
        int p = 0;
        while(fast and fast -> next)
        {
            fast = fast -> next -> next;
            slow = slow -> next;
            if(fast == slow)
            {
                p = 1;
                break;
            }
        }
        if(!p)
        {
           return NULL; 
        }
        fast = head;
        while(fast != slow)
        {
            fast = fast -> next;
            slow = slow -> next;
        }
        return slow;
    }
};