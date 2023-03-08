class Solution {
public:
    bool check(vector<int> piles,int h,int mid)
    {
        long long int ct = 0;
        for(int i = 0;i < piles.size();i++)
        {
            ct += ((piles[i] - 1) / mid) + 1;
        }
        return ct <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
    long long int low = 1;
        long long int high = 1e9,ans = -1;
        while(low <= high)
        {
            long long int mid = (high + low) >> 1;
            if(check(piles , h , mid))
            {
                ans = mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }
        return ans;
    }
};