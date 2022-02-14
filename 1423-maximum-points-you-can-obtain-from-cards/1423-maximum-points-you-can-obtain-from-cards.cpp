class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int n = card.size();
        int temp;
        int ans = 0 , sum = 0 , ct = 0;
        for(int i = n - 1 ; i >= 0 ; i--)
        {
            if(ct < k)
            {
                ct++;
                temp = i;
                sum += card[i];
            }
            else
                break;
        }
        ans = sum;
        for(int i = 0 ; i < k ;i++)
        {
            sum += card[i];
            sum -= card[temp++];
            ans = max(ans , sum);
        }
        return ans;
        
    }
};