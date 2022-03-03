class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin() , beans.end());
        long long sum = 0  , n = beans.size();
        for(auto x : beans)
            sum += x;
        long long ans = sum;
        // cout<<sum<<" ";
        for(int i = 0 ; i < n ;i++)
        {
            ans = min(ans , sum - (n - i) * beans[i]);
        }
        return ans;
        
        
    }
};