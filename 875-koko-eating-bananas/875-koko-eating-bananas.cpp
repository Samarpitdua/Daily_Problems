class Solution {
public:
    bool check(vector<int> piles,int h,int mid)
    {
        int ct = 0;
        for(int i = 0;i < piles.size();i++)
        {
            ct += ((piles[i] - 1) / mid) + 1;
        }
        return ct <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
    int low = 1;
        int high = 1e9,ans = -1;
        while(low <= high)
        {
            int mid = (high + low) >> 1;
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