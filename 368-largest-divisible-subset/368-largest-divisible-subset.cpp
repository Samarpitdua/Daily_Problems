class Solution {
public:
    int solve(vector<int>& nums , int n , vector<int>& dp , vector<int>& ans){
        int f = 0 , maxi = 0;
	    for(int i = 1; i < n ;i++){
	        for(int j =0 ; j < i ;j++){
	            if(nums[i] > nums[j] and nums[i] % nums[j] == 0)
                {
                    if(dp[i] <= dp[j])
                    {
                        dp[i] = 1 + dp[j];
                        ans[i] = j;
                    }
                }
	        }
            if(dp[i] > maxi)
            {
                maxi = dp[i];
                f = i;
            }
	    }
        return f;
	}
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        vector<int> dp(n , 1) , ans(n , -1) , temp;
        int f = solve(nums ,n , dp , ans);
        temp.push_back(nums[f]);
        while(1){
            f = ans[f];
            if(f == -1)
                break;
            else
                temp.push_back(nums[f]);
        }
        return temp;
    }
};