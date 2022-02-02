class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = p.size();
        vector<int> freq(26 , 0) , freq2(26 , 0) , ans;
        for(auto x : p)
            freq[x - 'a']++;
        if(p.size() > s.size())
            return ans;
        for(int i = 0 , j = 0; j <= s.size() ;)
        {
            while(j < p.size())
            {
                freq2[s[j] - 'a']++;
                j++;
                continue;
            }
            if(freq == freq2)
                ans.push_back(i);
            freq2[s[i] - 'a']--;
            
            if(j==s.size())
                break;
            freq2[s[j] - 'a']++;
            i++ , j++;
            
        }
        return ans;
    }
};