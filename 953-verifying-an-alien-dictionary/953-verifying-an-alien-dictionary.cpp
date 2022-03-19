class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char , char> mp;
        vector<string> v;
        char ch = 'a';
        for(int i = 0 ;i < 26 ;i++)
        {
            mp[order[i]] = ch;
            ch =char(ch + 1);
        }
        
        for(auto x : words)
        {
            string ans="";
            for(int i = 0 ; i < x.size() ;i++)
            {
                ans += mp[x[i]];
            }
            v.push_back(ans);
            //cout<<ans<<" ";
        }
        //cout<<"\n";
        return (is_sorted(v.begin() , v.end()));
    }
};