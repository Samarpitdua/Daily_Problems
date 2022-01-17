class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char , string> mp;
        string t= "";
        vector<string> v;
        for(int i = 0 ; i < s.size() ; i++)
        {
            if(s[i] == ' ')
                v.push_back(t),t = "";
            else 
                t += s[i];
        }
        unordered_set<string>st;
        v.push_back(t);
        int i = 0;
        int  n = v.size();
        vector<string>v2(n);
        for(int i = 0 ;i<26;i++)
        {
            mp[char(i + 'a')] = "0";
         }
        
        for(auto x : v)
            v2[i++] = x;
        //cout<<v2.size()<<" ";
        if(v2.size() != pattern.size())
            return false;
        for(int i = 0; i < pattern.size() ; i++)
        {
            cout<<mp[pattern[i]]<<" ";
            if(mp[pattern[i]] != "0")
            {
                if(mp[pattern[i]] == v2[i])
                    continue;
                else
                    return false;
            }
            else
            {
                cout<<pattern[i]<<" ";
                if(st.find(v2[i])==st.end())
                {
                    mp[pattern[i]] = v2[i];
                    st.insert(v2[i]);
                }
                else
                    return false;
            }
        }
        return true;
            
        
    }
};