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
    ListNode* oddEvenList(ListNode* head) {
        if(!head or !head -> next)
            return head;
        ListNode* even = head -> next;
        ListNode* odd = head ;
        ListNode* even_start = even;
        while(odd -> next and even -> next)
        {
            odd -> next = even -> next;
            even -> next = even -> next -> next;
            odd = odd -> next;
            even = even -> next;
        }
        odd -> next = even_start;
        return head;
    }
};