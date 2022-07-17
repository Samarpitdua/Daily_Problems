class Solution {
public:
    static bool comp(string& s , string& t){
        return s.size() < t.size();
    }
    bool find(string& s , string& t){
        int n = s.size() , m = t.size();
        if(n != (m + 1))
            return false;
        int ct = 0;
        for(int i = 0 , j = 0; i < n and j < n;){
            if(s[i] == t[j])
            {
                i++ , j++;
                continue;
            }
            else
            {
                if(ct)
                    return false;
                else
                    ct = 1;
             i++;           
            }
        }
        return true;
    }
    void solve(vector<string>& nums , int n , vector<int>& dp){
	    for(int i = 1; i < n ;i++){
	        for(int j =0 ; j < i ;j++){
	            if(find(nums[i] , nums[j]))
	                dp[i] = max(dp[i] , 1 + dp[j]);
	        }
            // cout<<dp[i]<<" ";
	    }
        
	}

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin() , words.end() ,comp);
        vector<int> dp(n , 1);
        solve(words , n , dp);
        return *max_element(dp.begin() , dp.end());
    }
};