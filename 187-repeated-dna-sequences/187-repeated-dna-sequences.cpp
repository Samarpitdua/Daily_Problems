class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        unordered_map<string , int> mp;
        string t = "";
        if(s.size() < 10)
            return ans;
        for(int i = 0 ; i < 10 ;i++)
        {
            t += s[i];
        }
        mp[t]++;
        for(int i = 10 ; i < s.size() ;i++)
        {
            t.erase(t.begin());
            t += s[i];
            mp[t]++;
            //cout<<t<<"\n";
        }
        for(auto x : mp)
        {
            if(x.second > 1)
                ans.push_back(x.first);
        }
        return ans;
        
    }
};