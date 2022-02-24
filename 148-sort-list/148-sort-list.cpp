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
    ListNode* sortList(ListNode* head) {
        if(!head or !head -> next)
            return head;
        ListNode* slow  = head , *fast = head ;
        while(fast -> next and fast -> next -> next)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        fast= slow -> next;
        slow -> next = NULL;
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(fast);
        
        return merge(l1 , l2);
    }
    ListNode* merge(ListNode* head1 , ListNode* head2)
    {
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        while(head1 and head2)
        {
            if(head1 -> val < head2 -> val)
            {
                temp -> next = head1;
                head1 = head1 -> next;
            }
            else
            {
                temp -> next = head2;
                head2 = head2 -> next;
            }
            temp = temp -> next;
        }
        if(head1)
            temp -> next = head1;
        else
            temp -> next = head2;
        return dummy->next;
    }
};