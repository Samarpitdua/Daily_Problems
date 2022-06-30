class Solution {
public:
    bool subset(vector<int>& nums,int target)
    {
        int n=nums.size();
        vector<vector<bool>>dp(n+1,vector<bool>(target+1,false));
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=target;j++)
            {
                if(j==0)
                    dp[i][j]=true;
                else if(i==0)
                    dp[i][j]=false;
                    
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=target;j++)
            {
                if(dp[i-1][j]==true)
                    dp[i][j]=true;
                else{
                int val=j-nums[i-1];
                if(val==0)
                {
                    dp[i][j]=true;
                }
                else if(val>0)
                {
                    dp[i][j]=dp[i-1][val];
                }
                }
            }
        }
        return dp[n][target];
    }
    int solve(vector<int>& nums , int target , vector<vector<int>>& dp , int ind){
        if(ind < 0)
            return 0;
        if(target == 0)
            return 1;
        if(dp[ind][target] != -1)
            return dp[ind][target];
        int a = 0 , b = 0;
        if(nums[ind] <= target)
        {
             a = solve(nums , target - nums[ind] , dp , ind - 1);
        }
        b = solve(nums , target , dp , ind - 1);
        return dp[ind][target] = a or b;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0 , target;
        for(int i = 0 ; i < n ;i++)
            sum += nums[i];
        if(sum & 1)
            return false;
        else
            target = sum/2;
        vector<vector<int>>dp(n + 1 , vector<int>(target + 1 , -1));
        return solve(nums , target , dp , n - 1);
            
    }
};