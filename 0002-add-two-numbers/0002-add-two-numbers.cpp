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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head, *temp;
        head = new ListNode(0);
        temp = head;
        int carry = 0;
        while(l1 and l2)
        {
            int sum = l1 -> val + l2 -> val + carry;
            if(sum > 9)
                carry = 1;
            else
                carry = 0;
            ListNode* newnode = new ListNode(sum % 10);
            temp -> next = newnode;
            temp = newnode;
            l2 = l2 -> next;
            l1 = l1 -> next;
        }
        while(l1)
        {
            int sum = l1 -> val + carry;
            if(sum > 9)
                carry = 1;
            else
                carry = 0;
            ListNode* newnode = new ListNode(sum % 10);
            temp -> next = newnode;
            temp = newnode;
            l1 = l1 -> next;
        }
        while(l2)
        {
            int sum = l2 -> val + carry;
            if(sum > 9)
                carry = 1;
            else
                carry = 0;
            ListNode* newnode = new ListNode(sum % 10);
            temp -> next = newnode;
            temp = newnode;
            l2 = l2 -> next;
        }
        if(carry)
        {
            ListNode* newnode = new ListNode(1);
            temp -> next = newnode;
            temp = newnode;
        }
        return head -> next;
        
    }
};