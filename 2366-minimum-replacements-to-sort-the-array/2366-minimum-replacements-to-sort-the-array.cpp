#define ll long long
class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        map<ll , ll> mp;
        long long int n = nums.size();
        
        int mini = nums[n - 1];
        long long ct = 0 , ans = 0;
        for(int i = n - 2 ; i >= 0 ;i--){
            ct = nums[i] / mini;   
            if(nums[i] % mini != 0){
                ct++;
                mini = nums[i] / ct;
            }   
		    ans += ct - 1;
        }
        return ans;
    }
};