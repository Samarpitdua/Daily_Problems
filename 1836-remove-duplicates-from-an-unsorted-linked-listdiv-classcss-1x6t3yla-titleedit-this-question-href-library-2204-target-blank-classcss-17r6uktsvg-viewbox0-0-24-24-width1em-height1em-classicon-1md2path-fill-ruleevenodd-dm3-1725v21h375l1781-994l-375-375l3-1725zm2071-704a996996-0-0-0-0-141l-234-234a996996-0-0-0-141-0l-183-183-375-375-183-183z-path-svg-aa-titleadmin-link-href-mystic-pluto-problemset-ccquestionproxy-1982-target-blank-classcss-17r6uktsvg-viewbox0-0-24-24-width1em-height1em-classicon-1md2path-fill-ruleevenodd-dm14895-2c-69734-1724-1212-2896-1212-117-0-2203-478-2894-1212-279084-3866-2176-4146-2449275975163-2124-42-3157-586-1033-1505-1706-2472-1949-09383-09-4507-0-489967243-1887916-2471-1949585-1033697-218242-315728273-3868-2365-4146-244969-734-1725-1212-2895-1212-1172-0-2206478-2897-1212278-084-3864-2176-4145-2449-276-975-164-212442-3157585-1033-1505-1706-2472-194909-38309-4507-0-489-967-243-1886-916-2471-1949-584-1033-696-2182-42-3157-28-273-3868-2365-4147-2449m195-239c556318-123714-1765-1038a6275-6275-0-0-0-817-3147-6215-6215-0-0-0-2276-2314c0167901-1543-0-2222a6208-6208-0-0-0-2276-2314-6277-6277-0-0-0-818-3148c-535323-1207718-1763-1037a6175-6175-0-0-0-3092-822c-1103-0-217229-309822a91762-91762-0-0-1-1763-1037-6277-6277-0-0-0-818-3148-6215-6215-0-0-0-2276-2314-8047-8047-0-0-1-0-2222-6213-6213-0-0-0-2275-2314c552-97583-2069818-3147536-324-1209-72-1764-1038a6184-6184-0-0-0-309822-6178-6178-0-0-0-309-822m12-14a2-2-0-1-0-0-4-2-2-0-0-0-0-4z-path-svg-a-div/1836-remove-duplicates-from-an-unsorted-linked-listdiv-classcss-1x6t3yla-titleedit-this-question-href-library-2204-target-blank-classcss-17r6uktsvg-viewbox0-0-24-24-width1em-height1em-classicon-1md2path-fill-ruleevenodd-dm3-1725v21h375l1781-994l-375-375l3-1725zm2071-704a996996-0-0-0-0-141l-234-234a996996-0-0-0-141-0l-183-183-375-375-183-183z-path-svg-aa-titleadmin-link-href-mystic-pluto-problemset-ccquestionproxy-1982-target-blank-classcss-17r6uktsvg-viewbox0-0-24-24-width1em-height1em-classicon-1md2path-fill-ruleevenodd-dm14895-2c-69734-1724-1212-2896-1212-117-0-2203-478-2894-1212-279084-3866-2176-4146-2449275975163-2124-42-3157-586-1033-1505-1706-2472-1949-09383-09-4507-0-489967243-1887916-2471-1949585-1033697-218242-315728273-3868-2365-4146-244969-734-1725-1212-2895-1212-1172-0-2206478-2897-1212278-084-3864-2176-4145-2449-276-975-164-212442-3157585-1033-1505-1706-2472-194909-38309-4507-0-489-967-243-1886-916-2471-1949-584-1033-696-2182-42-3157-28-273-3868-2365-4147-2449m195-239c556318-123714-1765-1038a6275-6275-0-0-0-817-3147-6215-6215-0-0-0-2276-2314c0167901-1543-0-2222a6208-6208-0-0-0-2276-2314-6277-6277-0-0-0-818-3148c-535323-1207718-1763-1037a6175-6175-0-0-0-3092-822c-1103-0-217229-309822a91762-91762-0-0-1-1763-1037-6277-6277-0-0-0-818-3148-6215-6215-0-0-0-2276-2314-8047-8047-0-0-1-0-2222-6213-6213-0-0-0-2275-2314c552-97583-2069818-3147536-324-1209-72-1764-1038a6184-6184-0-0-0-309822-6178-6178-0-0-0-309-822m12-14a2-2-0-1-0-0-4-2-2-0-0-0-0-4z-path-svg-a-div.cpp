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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        unordered_map<int , int> mp;
        ListNode* temp = head;
        while(temp){
            mp[temp -> val]++;
            temp = temp -> next;
        }
        while(head and mp[head -> val] > 1)
            head = head -> next;
        temp = head;
        while(temp){
            if(temp -> next and mp[temp -> next -> val] > 1)
            {
                temp -> next = temp -> next -> next;
            }
            else if(!temp -> next)
                break;
            else
                temp = temp -> next;
        }
        return head;
        
    }
};