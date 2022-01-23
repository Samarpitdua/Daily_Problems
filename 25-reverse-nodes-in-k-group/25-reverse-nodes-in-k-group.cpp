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
        vector<vector<int>> ans;
        vector<int> v;
        ListNode* temp = head;
        while(temp)
        {
            v.push_back(temp -> val);
            if(v.size() == k)
            {
                reverse(v.begin() ,v.end());
                ans.push_back(v);
                v.clear();
            }
            temp = temp -> next;
        }
        if(v.size() > 0)
         ans.push_back(v);
        temp = head;
        for(auto x : ans)
        {
            for(auto y : x)
            {
                temp -> val = y;
                temp = temp -> next;
            }
        }
        return head;
    }
};