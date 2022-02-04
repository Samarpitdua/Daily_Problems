class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int , int> mp;
        int ans = 0 , ct = 0 ;
       
        for(int i = 0 ; i < nums.size() ;i++)
        {
            if(nums[i] == 0)
                ct++;
            else
                ct--;
            
            if(ct == 0)
                ans = i + 1;
            
            else if(mp.find(ct) != mp.end())
                ans = max(ans , i - mp[ct] );

            else
                mp[ct] = i ;
        }
        return ans;
    }
};