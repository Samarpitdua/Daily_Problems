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
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return head;
        else if(!head -> next)
            return head;
        ListNode* temp , *prev;
        prev = NULL;
        temp = head;
        while(temp)
        {
            temp = temp -> next;
            head -> next = prev;
            prev = head;
            head = temp;
        }
        return prev;       
    }
};