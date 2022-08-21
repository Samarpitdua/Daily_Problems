class Solution {
public:
    string largestPalindromic(string num) {
        map<char , int> mp;
        int ct = 0;
        for(auto x : num)
        {
            if(x == '0')
                ct++;
                mp[x]++;
        }
        if(ct == num.size())
            return "0";
        string s ="" , t ="" , x2="";
        int p = 0;
        for (auto x = mp.rbegin(); x != mp.rend(); x++)
        {
            if(x->second % 2 == 0 or p == 1)
            {
                int diff = x->second / 2;
                for(int i = 0 ; i < diff ;i++)
                {
                    s += (x->first);
                }
                for(int i = 0 ; i < diff ;i++)
                {
                    t += (x->first);
                }
            }
            else if(p == 0)
            {
                p = 1;
                x2 += x->first;
                int diff = x->second / 2;
                for(int i = 0 ; i < diff ;i++)
                {
                    s += (x->first);
                }
                for(int i = 0 ; i < diff ;i++)
                {
                    t += (x->first);
                }
            }
        }
        reverse(t.begin() , t.end());
        string ans;
        ans = s + x2 + t;
        int i = 0;
        for( ; i < ans.size() ;i++)
        {
            if(ans[i] == '0')
            {
                ans.pop_back();
            }
            else
                break;
        }
        string ans2 =  ans.substr(i);
        return ans2;
    }
};