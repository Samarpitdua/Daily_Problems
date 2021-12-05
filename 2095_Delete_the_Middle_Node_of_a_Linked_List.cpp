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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* prev = head;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast -> next and fast -> next -> next)
        {
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        if(slow == head)
        {
            if(fast -> next)
            {
                head -> next = NULL;
                return head;
            }
            head = NULL;
            return head;
        }
        else if(!fast -> next)
        {
            prev -> next = slow -> next;
        }
        else
        {
            prev = slow;
            slow = slow -> next;
            prev -> next = slow -> next;
        }
        return head;
        
    }
};
