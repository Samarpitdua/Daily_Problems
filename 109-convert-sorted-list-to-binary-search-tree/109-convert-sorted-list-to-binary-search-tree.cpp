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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(ListNode* head , ListNode* tail){
        if(head == tail)
            return NULL;
        if(head -> next == tail){
            TreeNode* newnode = new TreeNode(head -> val);
            return newnode;
        }
        ListNode* slow = head , *fast = head;
        while(fast != tail and fast -> next != tail){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        TreeNode* newnode = new TreeNode(slow -> val);
        newnode -> left = solve(head , slow);
        newnode -> right = solve(slow -> next , tail);
        return newnode;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        return solve(head , NULL);
    }
};