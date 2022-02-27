class Solution {
public:
    int isPrefixOfWord(string sentence, string pref) {
        map<int , string> mp;
        string t = "";
        int ct = 1;
        for(auto x : sentence)
        {
            if(x == ' ')
            {
                mp[ct++] = t ;
                t = "";
            }
            else
                t += x;
        }
        mp[ct] = t;
        for(auto x : mp)
        {
            if(x.second.find(pref) == 0)
                return x.first;
        }
        return -1;
    }
};