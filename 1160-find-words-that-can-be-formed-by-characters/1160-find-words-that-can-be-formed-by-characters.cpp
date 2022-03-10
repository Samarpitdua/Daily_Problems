class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> freq(26 ,0) , freq2(26 ,0);
        int ans = 0;
        for(auto x : chars)
        {
            freq[x - 'a']++;
        }
        for(auto x : words)
        {
            freq2 = freq;
            int p = 1;
            for(auto y : x)
            {
                if(freq2[y - 'a'])
                {
                    freq2[y - 'a']--;
                }
                else
                {
                    p = -1;
                    break;
                }
                    
            }
            if(p == -1)
                continue;
            else
            {
                int n = x.size();
                ans += n;
            }
        }
        return ans;
    }
};