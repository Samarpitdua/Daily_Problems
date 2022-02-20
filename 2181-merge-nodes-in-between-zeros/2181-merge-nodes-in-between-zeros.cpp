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
    ListNode* mergeNodes(ListNode* head) {
        vector<int> v;
        head = head -> next;
        int sum = 0;
        while(head)
        {
            sum += head -> val;
            if(head -> val == 0)
                v.push_back(sum) , sum = 0;
            head = head -> next;
        }
        ListNode* temp = new ListNode(0);
        ListNode* head2 = temp;
        for(auto x : v)
        {
            ListNode* temp2 = new ListNode(x);
            temp -> next = temp2;
            temp = temp -> next;
        }
        return head2 -> next;
        
        
    }
};