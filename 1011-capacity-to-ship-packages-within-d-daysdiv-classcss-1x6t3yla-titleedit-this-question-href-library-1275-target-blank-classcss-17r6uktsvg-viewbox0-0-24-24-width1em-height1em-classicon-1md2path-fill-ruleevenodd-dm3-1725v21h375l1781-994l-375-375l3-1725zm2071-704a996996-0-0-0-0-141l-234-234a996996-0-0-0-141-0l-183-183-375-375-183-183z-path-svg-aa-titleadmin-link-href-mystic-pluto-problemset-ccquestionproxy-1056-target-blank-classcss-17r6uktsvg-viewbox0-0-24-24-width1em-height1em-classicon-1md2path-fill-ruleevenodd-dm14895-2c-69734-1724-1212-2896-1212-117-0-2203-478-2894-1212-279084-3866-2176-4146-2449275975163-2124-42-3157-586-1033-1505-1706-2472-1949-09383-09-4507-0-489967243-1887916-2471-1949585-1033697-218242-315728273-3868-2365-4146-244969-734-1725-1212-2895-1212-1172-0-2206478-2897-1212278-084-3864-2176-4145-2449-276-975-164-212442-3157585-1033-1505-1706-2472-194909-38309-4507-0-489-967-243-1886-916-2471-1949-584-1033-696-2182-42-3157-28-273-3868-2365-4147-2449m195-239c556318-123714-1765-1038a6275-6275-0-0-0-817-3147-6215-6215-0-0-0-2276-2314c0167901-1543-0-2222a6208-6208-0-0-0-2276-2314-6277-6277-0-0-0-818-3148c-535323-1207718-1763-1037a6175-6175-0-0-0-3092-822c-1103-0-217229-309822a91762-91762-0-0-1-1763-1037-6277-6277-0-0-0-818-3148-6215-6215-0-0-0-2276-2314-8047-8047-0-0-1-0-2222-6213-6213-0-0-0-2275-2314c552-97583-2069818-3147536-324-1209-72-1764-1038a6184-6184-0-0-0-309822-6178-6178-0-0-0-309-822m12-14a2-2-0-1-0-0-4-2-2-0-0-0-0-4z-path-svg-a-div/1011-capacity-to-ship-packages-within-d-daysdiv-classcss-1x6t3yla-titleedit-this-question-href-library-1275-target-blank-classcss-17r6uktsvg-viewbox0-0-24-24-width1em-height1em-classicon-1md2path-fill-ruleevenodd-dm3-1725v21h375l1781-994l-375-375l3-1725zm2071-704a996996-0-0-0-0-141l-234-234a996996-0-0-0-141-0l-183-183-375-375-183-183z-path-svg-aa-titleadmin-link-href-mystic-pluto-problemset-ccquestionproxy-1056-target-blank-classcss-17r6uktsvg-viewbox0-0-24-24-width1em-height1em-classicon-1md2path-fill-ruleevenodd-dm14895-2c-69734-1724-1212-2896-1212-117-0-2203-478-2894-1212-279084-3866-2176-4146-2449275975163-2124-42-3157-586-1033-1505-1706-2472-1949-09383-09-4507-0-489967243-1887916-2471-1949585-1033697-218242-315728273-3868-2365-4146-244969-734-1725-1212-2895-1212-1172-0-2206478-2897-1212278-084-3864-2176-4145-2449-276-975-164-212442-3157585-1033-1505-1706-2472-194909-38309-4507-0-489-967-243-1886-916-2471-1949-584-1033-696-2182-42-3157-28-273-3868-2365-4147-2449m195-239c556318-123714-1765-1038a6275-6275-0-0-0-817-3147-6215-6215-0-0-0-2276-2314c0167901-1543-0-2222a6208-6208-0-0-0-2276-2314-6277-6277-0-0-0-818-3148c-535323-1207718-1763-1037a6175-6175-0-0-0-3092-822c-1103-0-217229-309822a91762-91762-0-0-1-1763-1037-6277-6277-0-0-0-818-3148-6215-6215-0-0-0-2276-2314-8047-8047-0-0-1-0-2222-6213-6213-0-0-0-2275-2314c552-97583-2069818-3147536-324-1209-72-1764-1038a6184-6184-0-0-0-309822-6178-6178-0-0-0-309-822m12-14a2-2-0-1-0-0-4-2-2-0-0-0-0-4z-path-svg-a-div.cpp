class Solution
{
    public:
        int check(int mid , int d , vector<int>& w)
        {
            int sum = 0;
            int days = 1;
            for(int i = 0 ; i < w.size() ;i++)
            {
                if(w[i] > mid)
                {
                    return 0;
                }
                if((sum + w[i]) <= mid)
                {
                    sum += w[i];
                }
                else{
                    days++;
                    sum = w[i];
                }
            }
            return (days <= d);
        }
        int shipWithinDays(vector<int> &weights, int days)
        {
            long long int sum = 0;
            for (auto x: weights)
            {
                sum += x;
            }
            int low = 0, high = sum;
            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                if(!check(mid , days , weights))
                {
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
            return low;
        }
    
};