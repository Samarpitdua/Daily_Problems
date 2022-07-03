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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> mat(m , vector<int>(n , -1));
        int dir = 1;
        int up = 0 , down = m - 1 , left = 0 , right = n - 1;
        while(1){
            if(!head)
                    return mat;
        if(dir == 1){
        for(int i = left ; i <= right ;i++)
        {
                if(!head)
                    return mat;
            mat[up][i] = head -> val;
            head = head -> next;
        }
            up++;
            dir = 2;
        }
        else if(dir == 2){
            for(int i = up ; i <= down ;i++)
            {
                if(!head)
                    return mat;
                mat[i][right] = head -> val;
                head = head -> next;
            }
            right--;
            dir = 3;
        }
        else if(dir == 3){
            for(int i = right ; i >= left ;i--)
            {
                if(!head)
                    return mat;
                mat[down][i] = head -> val;
                head = head -> next;
            }
            down--;
            dir = 4;
        }
        else if(dir == 4){
            for(int i = down ; i >= up ;i--)
            {
                if(!head)
                    return mat;
                mat[i][left] = head -> val;
                head = head -> next;
            }
            left++;
            dir = 1;
        }
    }
    return mat;
    }
};