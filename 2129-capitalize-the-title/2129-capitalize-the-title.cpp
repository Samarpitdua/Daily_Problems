class Solution {
public:
    string capitalizeTitle(string t) {
        vector<string> ans;
        string s = "";
        for(int i = 0;i < t.size();i++)
        {
            if(t[i] == ' ')
            {
                ans.push_back(s);
                s = "";
            }
            else
                s += t[i];
        }
        ans.push_back(s);
        
        string ans2="";
        
        for(auto x : ans)
        {
            int n = x.size();
            if(n <= 2)
            {
                for(auto y : x)
                {
                    if(y >= 'A' and y <= 'Z')
                        ans2 += (y + 32);
                    else
                        ans2 += y;
                    
                }
                ans2 += " ";
            }
            else
            {
                for(int i = 0;i < x.size();i++)
                {
                    if(i == 0 and x[i] >='a' and x[i] <= 'z')
                        ans2 += (x[i] - 32);
                    else if(i != 0 and x[i] >= 'A' and x[i] <= 'Z')
                        ans2 += (x[i] + 32);
                    else
                        ans2+=x[i];
                }
                ans2 += " ";
            }
        }
        string ans3 = "";
        for(int i = 0;i < ans2.size()-1;i++)
            ans3 += ans2[i];
        return ans3;
    }
};