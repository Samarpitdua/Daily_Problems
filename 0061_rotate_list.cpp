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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        if(!head)
            return head;
        int ct = 1;
        while(temp -> next)
        {
            ct++;
            temp = temp->next;
        }
        
        temp -> next = head;
        
        k = k % ct;
        k = ct - k;
        
        int a = 1;
         temp = head;
        ListNode* loveu;
        while(a<k)
        {
            a++; 
            temp = temp->next;
        }
        //cout<<temp->val;
         loveu=temp->next;
        temp -> next = NULL;
        return loveu;
    }
};
