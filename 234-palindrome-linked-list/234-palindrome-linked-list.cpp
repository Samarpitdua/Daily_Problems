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
    ListNode * temp;
    bool isPalindrome(ListNode* head) {
        if(!head or !head -> next)
            return true;
        ListNode* fast = head , *slow = head , *prev = head;
        
        //find middle element
        while(fast and fast -> next)
        {
            fast = fast -> next -> next;
            prev = slow;
            slow = slow -> next;
        }
        if(!fast)
            slow = prev;
        //reverse second half
        slow -> next = reverseList(slow -> next);
        slow = slow -> next;
        //check
        while(slow)
        {
            if(head -> val != slow -> val)
                return false;
            head = head -> next;
            slow = slow -> next;
        }
        return true;
    }
};