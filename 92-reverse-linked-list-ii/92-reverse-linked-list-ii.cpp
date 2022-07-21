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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head or left == right)
            return head;
        ListNode* temp , *prev , *ans = head ,*prev2 = NULL;
        int ct = 0;
        while(head)
        {
            ct++;
            if(ct == left)
            {
                prev = head;
                ListNode* temp2 = prev;
                head = head -> next;
                while(head)
                {
                       ct++;
                        temp = head -> next;
                        head -> next = prev;
                        prev = head;
                        head = temp;
                        if(ct == right)
                            break;
                }
                temp2 -> next = temp;
                if(left == 1)
                    ans = prev;
                if(prev2)
                    prev2 -> next = prev;
            }
            else
            {
                prev2 = head ;
                head = head -> next;
            }
        }
        return ans;
        
    }
};