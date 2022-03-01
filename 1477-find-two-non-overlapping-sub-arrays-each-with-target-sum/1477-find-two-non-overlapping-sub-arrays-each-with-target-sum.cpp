class Solution {
public:
    vector<int> solve(vector<int>& v , int target)
    {
        int n = v.size();
        vector<int> presum(n, 0);
        unordered_map<int, int> mp;
        vector<int> ans(n, n + 1);
        
        mp[0] = -1;
        for(int i = 0; i < v.size(); ++i) 
        {
            presum[i] = i == 0 ? v[i] : v[i] + presum[i-1];
            int len = v.size() + 1;
            
            if(mp.find(presum[i] - target) != mp.end())
            {
                len = i - mp[presum[i]-target];
            }
            mp[presum[i]] = i;
            ans[i] = i == 0 ? len : min(ans[i-1], len);    
        }
        return ans;
    }
    int minSumOfLengths(vector<int>& a , int target) {
        int sum = 0;
        int n = a.size();
        vector<int> left = solve(a , target) ;
        vector<int> temp = a;
        reverse(temp.begin() , temp.end());
        vector<int> right = solve(temp , target);
         int ans = a.size() + 1;
        for(int i = 0 ; i < n - 1;i++)
        {
            ans = min(ans , left[i] + right[n - 1 - i - 1]);
        }
        if(ans == (a.size() + 1))
            return -1;
        return ans;
        
    }
};