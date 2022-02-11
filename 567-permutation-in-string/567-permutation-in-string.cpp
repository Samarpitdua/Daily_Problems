class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26 , 0) , freq2(26 , 0);
        int n = s1.size() , m = s2.size();
        if(n > m)
            return false;
        for(auto x : s1)
        {
            freq[x - 'a']++;
        }
        for(int i = 0 , j = 0; j < m ; )
        {
            if(j < n)
            {
                freq2[s2[j] - 'a']++;
                j++;
                continue;
            }
            if(freq2 == freq)
                return true;
            freq2[s2[i] - 'a']--;
            freq2[s2[j] - 'a']++;
            i++;
            j++;
        }
        return (freq == freq2);
            
        
        
        return false;
    }
};