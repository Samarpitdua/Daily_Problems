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
        while(1)
        {
            if(headA == headB)
                return headA;
            if(! headA)
                headA = temp2;
            else
                headA = headA ->next;
            if(! headB)
                headB = temp1;
            else
                headB = headB -> next;
        }
        
    }
};
