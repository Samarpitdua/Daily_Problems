class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n = s.size() , m = t.size();
        string ans1 = "" , ans2 = "";
        for(int i = 0 ;i < n ; i++)
        {
            if(s[i] == '#' and ans1 != "")
                ans1.pop_back();
            else if(s[i] == '#' and ans1 == "")
                continue;
            else
                ans1 += s[i];
        }
        
        for(int i = 0 ;i < m ; i++)
        {
            if(t[i] == '#' and ans2 != "")
                ans2.pop_back();
            else if(t[i] == '#' and ans2 == "")
                continue;
            else
                ans2 += t[i];
        }
        return ans1 == ans2;
        
        
    }
};