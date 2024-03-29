class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26] = {0};
        for(auto x : s)
            freq[x - 'a']++;
        for(int i = 0 ; i < s.size() ; i++)
        {
            if(freq[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
        
    }
};