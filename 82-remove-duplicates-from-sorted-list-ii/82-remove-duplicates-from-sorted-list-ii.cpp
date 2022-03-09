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
    ListNode* deleteDuplicates(ListNode* head)
    {
        if (!head) return 0;
        if (!head->next) return head;
        ListNode * ans = NULL ,*temp = NULL;
        while(1)
        {
            if(!head)
                break;
            if(head->next and head->val == head->next->val)
            {
                while(head->next and head->val == head->next->val)
                {
                    head=head->next;
                }
                head=head->next;
            }
            else
            {
                if(temp==NULL)
                {
                    temp=new ListNode(head->val);
                    ans = temp;
                    head=head->next;
                }
                else
                {
                    temp->next=new ListNode(head->val);
                    temp=temp->next;
                    head=head->next;
                }
            }
        }
        return ans;
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