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
    int pairSum(ListNode* head) {
        vector <int> v;
        int maxi = 0;
        while(head)
        {
            v.push_back(head->val);
            head = head -> next;
        }
        int n = v.size();
        vector<int> v2(n);
        int i = 0;
        for(auto x : v)
        {
            v2[i++] = x;
        }
        for(int i = 0,j = n - 1;i < j;i++ , j--)
        {
            maxi = max(v2[i] + v2[j] , maxi);
        }
        return maxi;
    }
};