class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int ans = 0;
        int n = s.size();
        unordered_map<char , int> mp;
        for(int i = 0 , j = 0; i < n and j < n ;){
            mp[s[j]]++;
            while(mp.size() > 2)
            {
                mp[s[i]]--;
                if(mp[s[i]] == 0)
                    mp.erase(s[i]);
                i++;
            }
            ans = max(ans , j - i + 1);
            j++;
        }
        return ans;
    }
};