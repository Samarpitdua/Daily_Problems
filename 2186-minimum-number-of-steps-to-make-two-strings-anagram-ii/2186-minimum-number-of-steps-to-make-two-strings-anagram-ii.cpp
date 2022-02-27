class Solution {
public:
    int minSteps(string s, string t) {
        int ans = 0;
        int freq1[26] = {0} , freq2[26] = {0};
        for(int i = 0 ; i < s.size() ; i++)
            freq1[s[i] - 'a']++;
        for(int i = 0 ; i < t.size() ; i++)
            freq2[t[i] - 'a']++;
        for(int i = 0 ; i < 26 ;i++)
        {
            ans += abs(freq1[i] - freq2[i]);
        }
        return ans;
        
        
    }
};