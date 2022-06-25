class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(auto x : words)
        {
            map<char , char> mp;
            map<char , int> mp2;
            
            mp.clear();
            int p = 0;
            for(int i = 0 ; i < x.size() ;i++)
            {
                if(mp.find(x[i]) != mp.end())
                {
                    if(mp[x[i]] != pattern[i])
                    {
                        p = 1;
                        break;
                    }
                }
                else if(mp2[pattern[i]])
                {
                    p = 1;
                    break;
                }
                else
                {
                    mp[x[i]] = pattern[i];
                    mp2[pattern[i]] = 1;
                }
            }
            if(p == 1)
            {
                continue;
            }
            else
                ans.push_back(x);
        }
        return ans;
    }
};