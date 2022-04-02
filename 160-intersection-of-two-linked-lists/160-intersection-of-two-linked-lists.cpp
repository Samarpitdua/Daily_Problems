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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * temp1 = headA;
        ListNode * temp2 = headB;
        int p = 0;
        while(1)
        {
            if(headA == headB)
                return headA;
            if(headA -> next)
            {
                headA = headA -> next;
            }
            else if(p == 0)
                headA = temp2 , p = 1;
            else
                return NULL;
            if(headB -> next)
            {
                headB = headB -> next;
            }
            else
                headB = temp1;
            
        }
        
    }
};