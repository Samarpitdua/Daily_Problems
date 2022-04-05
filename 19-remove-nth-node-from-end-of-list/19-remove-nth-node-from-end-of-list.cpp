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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int temp = 0;
        ListNode* fast = head ,*slow = head , *prev;
        if(!head -> next)
            return NULL;
        
        while(temp < n)
        {
            fast = fast -> next;
            temp++;
        }
        if(!fast)
        {
            head = head -> next;
            return head;
        }
        while(fast -> next)
        {
            fast = fast -> next;
            slow = slow -> next;
        }
        slow -> next = slow -> next -> next;
        
        return head;
        
    }
};