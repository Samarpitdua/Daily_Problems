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
    ListNode* plusOne(ListNode* head) {
        ListNode* p = reverse(head);
        ListNode* tmp = p;
        while(p->val + 1 == 10){
            p->val = 0;
            if(!p->next) p->next = new ListNode(0);
            p = p->next;
        }
        p->val += 1;
        return reverse(tmp);
    }
    
    ListNode* reverse(ListNode* head){
        ListNode* pre = NULL, *cur = head, *next;
        while(cur){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};