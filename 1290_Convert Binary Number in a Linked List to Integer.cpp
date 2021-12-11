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
    int getDecimalValue(ListNode* head) {
        vector<int>v;
        long long ans = 0;
        while(head)
        {
            v.push_back(head->val);
            head=head->next;
        }
        long long int ct=0;
        reverse(v.begin(),v.end());
        for(auto x:v)
        {
            
            if(x==1)
            ans += pow(2,ct);
            ct++;
          //  cout<<ans<<":";
        }
        return ans;
    }
};
