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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return 0;
        if (!head->next) return head;
        
        int val = head->val;
        ListNode* p = head->next;
        
        if (p->val != val) 
        {
            head->next = deleteDuplicates(p);
            return head;
        } else
        {
            while (p && p->val == val) p = p->next;
            return deleteDuplicates(p);
        }
    }
};
// [1,2,3,3,4,4,5]
// [1,1,1,2,3]
// [1,1,1,2,2,2,3]
// [1,1,1,2,2,3,3,3,3]
// [1,2,3,4,5]
// [1,2,2,3]
// [1,2,3,3,3,4]
// [1,2,3,3]