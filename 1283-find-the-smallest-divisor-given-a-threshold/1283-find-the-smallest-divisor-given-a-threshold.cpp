class Solution {
public:
    int smallestDivisor(vector<int>& nums, int t) {
        long long int low = 1 , high = 1000000009;
        long long int ans = 0;
        while(low <= high)
        {
            long long int sum = 0;
            long long int mid = low + (high - low) / 2;
           
            for(auto x : nums)
            {
                sum += ceil(x / (double)mid);
            }
            long long int temp=sum;
            
            if(temp > t)
            {
                low = mid + 1;
            }
            else
                 high = mid - 1;
            
        }
        return low;
    }
};