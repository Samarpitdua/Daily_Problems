class Solution {
public:
    long long solve(vector<int>& time, long long int mid , int trips)
    {
        long long ans = 0;
        for(auto x : time)
        {
            ans += (mid / x);
        }
        return ans;
    }
    long long minimumTime(vector<int>& time, int trips) {
        long long low = 0 , high = 1e14;
        while(low <= high)
        {
            long long int mid = low + (high - low) / 2;
            long long tripsTaken = solve(time , mid , trips);
            if(tripsTaken >= trips)
            {
                high = mid - 1;
                continue;
            }
            else
                low = mid + 1;
                
        }
        return low;
        
    }
};