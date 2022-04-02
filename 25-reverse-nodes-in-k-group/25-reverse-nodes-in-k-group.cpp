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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int ct = 0;
        ListNode* temp = head;
        while(temp)
        {
            ct++;
            temp = temp -> next;
        }
        
        ct = ct / k;
        ListNode *dummy = new ListNode(0);
        dummy -> next = head;
        ListNode *prev = dummy , *curr , *nex;
        
        for(int i = 0 ; i < ct ; i++)
        {
            curr = prev -> next;
            nex = curr -> next;
            for(int j = 0 ; j < k - 1;j++)
            {
                curr->next = nex->next;
                nex->next = prev->next;
                prev->next = nex;
                nex = curr->next;
            }
            prev = curr;
        }
        return dummy -> next;;
    }
};