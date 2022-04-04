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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *start = head , *end = head;
        k--;
        while(k)
        {
            start = start -> next;
            k--;
        }
        ListNode* temp = start;
        while(start -> next)
        {
            start = start -> next;
            end = end -> next;
        }
        swap(temp -> val , end -> val);
        return head;
    }
};