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
        ListNode * ans = new ListNode();
        ListNode* ok = ans;
        int sum =0, carry = 0;
        while(l1 and l2)
        {
            sum = l1->val + l2->val + carry;
            ListNode * temp = new ListNode(sum % 10);
             carry = sum / 10;
            ans -> next = temp;
            ans = ans -> next;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        while(l1)
        {
             sum = l1 -> val + carry;
            ListNode * temp = new ListNode(sum % 10);
             carry = sum / 10;
            ans -> next = temp;
            ans = ans -> next;
            l1 = l1 -> next;
        }
        while(l2)
        {
             sum = l2 -> val + carry;
            ListNode * temp = new ListNode(sum % 10);
             carry = sum / 10;
            ans -> next = temp;
            ans = ans -> next;
            l2 = l2 -> next;
        }
        while(carry)
        {
            sum = carry;
            ListNode * temp = new ListNode(sum % 10);
             carry = sum / 10;
            ans -> next = temp;
            ans = ans -> next;
        }
        return ok -> next;
    }
};