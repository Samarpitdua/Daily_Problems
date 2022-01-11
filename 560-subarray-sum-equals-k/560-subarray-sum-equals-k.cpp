class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size() , ct = 0 , sum = 0 ,ans = 0;
        map<int,int>mp;
    //    mp[0]++;
        for(int i = 0 ;i < n ;i++)
        {
            int p=0;
            sum += nums[i];
            
            if(sum == k)
                ans++;
            if(mp.find(sum-k)!=mp.end())
                ans += mp[sum-k];
            mp[sum]++;
            cout<<ans<<" ";
        }
        cout<<"\n";
        return ans;
    }
};