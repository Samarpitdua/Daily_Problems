class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int sum = 0 , ans = 0;
        map<int , int> mp;
        mp[0] = 1;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            sum += nums[i];
            if(mp.find(sum - target) != mp.end())
            {
                mp.clear();
                mp[0] = 1;
                sum = 0;
                ans++;
            }
            else
            {
                mp[sum]++;
            }
        }
        return ans;
    }
};