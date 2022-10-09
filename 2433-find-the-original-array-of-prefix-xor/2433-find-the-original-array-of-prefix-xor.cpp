class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size() , xorr = 0;
        vector<int> ans(n);
        for(int i = 0 ; i < n ;i++)
        {
            ans[i] = xorr ^ pref[i];
            xorr ^= ans[i];
        }
        return ans;
    }
};