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
struct comp
{
    bool operator()(ListNode* a , ListNode* b)
    {
        return ((a -> val) > (b -> val));
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(0);
        ListNode* move = dummy;
        priority_queue<ListNode* , vector<ListNode*> , comp > pq;
        for(auto x : lists)
        {
            if(x)
                pq.push(x);
        }
        while(!pq.empty())
        {
            ListNode* temp = pq.top();
            pq.pop();
            if(temp and temp -> next)
                pq.push(temp -> next);
            move -> next = temp;
            move = move -> next;
        }
        return dummy -> next;
    }
};