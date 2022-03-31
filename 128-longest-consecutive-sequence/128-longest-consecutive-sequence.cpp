class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int , int> mp;
        if(nums.size() == 0)return 0;
        int ans = 1 ,ct = 1 ,p = -1;
        for(int i = 0 ; i < nums.size() ;i++)
            mp[nums[i]]++;
        int temp;
        for(auto x : mp)
        {
            if(p == -1)
            {
                p = 1;
                temp = x.first;
                continue;
            }
            else
            {
                if(x.first == temp + 1)
                {
                    temp = x.first;
                    ct++;
                }
                else
                {
                    temp = x.first;
                    ct = 1;
                }
                ans = max(ans , ct);
            }
        }
        return ans;
    }
};