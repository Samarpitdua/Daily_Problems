class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string temp = "" ; 
        int ct = 0;
        for(auto x : s)
        {
            if(x != '-')
                temp += x;
            
        }
        int n = temp.size();
        string ans = "";
        
        for(int i = n - 1 ; i >= 0 ;i--)
        {
            ans += toupper(temp[i]);
            ct++;
            if(i > 0 and ct % k == 0)
                ans += '-';
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};