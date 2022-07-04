class Solution {
public:
    int candy(vector<int>& r) {
        int n = r.size();
        vector<int> v(n , 0);
        int ans = 0;
        for(int i = 1 ; i < n ;i++){
            if(r[i] > r[i - 1])
                v[i] = 1 + v[i - 1];
        }
        for(int i = n - 2 ; i >= 0 ;i--){
            if(r[i] > r[i + 1])
                v[i] = max(v[i] , 1 + v[i + 1]);
        }
        
        for(auto x : v)
            ans += x;
        return ans + n;
        
    }
};