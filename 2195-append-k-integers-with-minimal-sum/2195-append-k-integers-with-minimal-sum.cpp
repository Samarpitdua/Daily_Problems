class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        unsigned long long int ans = 0;
        map<int,int> mp;
        ans = ((long long )k * (long long )(k + 1)) / 2;
        int temp=k+1;
        sort(nums.begin() , nums.end());
        for(int i = 0 ; i < nums.size(); i++)
        {
            if(mp[nums[i]] != 1 and nums[i] < temp)
            {
                ans -= nums[i];
                ans += temp;
                temp ++;
            }
            mp[nums[i]] = 1;
        }
        return ans;
    }
};