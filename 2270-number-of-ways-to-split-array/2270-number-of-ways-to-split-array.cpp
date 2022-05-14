#define ll long long 
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<ll> v(n);
        ll sum = 0 , ct = 0;
        for(int i = n - 1 ; i >= 0 ;i--)
        {
            v[i] = sum;
            sum += nums[i];
        }
        sum = 0;
        
        for(int i = 0 ; i < n - 1 ;i++)
        {
            sum += nums[i];
            if(sum >= v[i])
                ct++;
        }
        return ct;
    }
};