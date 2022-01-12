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
        int ct=1;
        ListNode*k =head;
        while(head->next!=NULL)
        {
            ct++;
            head=head->next;
        }
        if(ct==1)
        {
            head=NULL;
            return head;
        }
        head=k;
        int diff=ct-n+1;
        int u=1;
        while(u!=diff)
        {
            u++;
            if(u==diff)
                break;
            head=head->next;
        }
        if(u==1)
        {
            k=k->next;
            return k;
        }
        head->next=head->next->next;
        return k;
    }
};