class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        map<int , int> mp;
        int maxi = 0;
        for(int i = 0 ; i < arr.size() ; i++)
        {
            if(mp.find(arr[i] - diff) != mp.end())
            {
                mp[arr[i]] = 1 + mp[arr[i] - diff];
            }
            else
            {
                mp[arr[i]] = 1;
            }
            maxi = max(maxi , mp[arr[i]]);
        }
        return maxi;
    }
};