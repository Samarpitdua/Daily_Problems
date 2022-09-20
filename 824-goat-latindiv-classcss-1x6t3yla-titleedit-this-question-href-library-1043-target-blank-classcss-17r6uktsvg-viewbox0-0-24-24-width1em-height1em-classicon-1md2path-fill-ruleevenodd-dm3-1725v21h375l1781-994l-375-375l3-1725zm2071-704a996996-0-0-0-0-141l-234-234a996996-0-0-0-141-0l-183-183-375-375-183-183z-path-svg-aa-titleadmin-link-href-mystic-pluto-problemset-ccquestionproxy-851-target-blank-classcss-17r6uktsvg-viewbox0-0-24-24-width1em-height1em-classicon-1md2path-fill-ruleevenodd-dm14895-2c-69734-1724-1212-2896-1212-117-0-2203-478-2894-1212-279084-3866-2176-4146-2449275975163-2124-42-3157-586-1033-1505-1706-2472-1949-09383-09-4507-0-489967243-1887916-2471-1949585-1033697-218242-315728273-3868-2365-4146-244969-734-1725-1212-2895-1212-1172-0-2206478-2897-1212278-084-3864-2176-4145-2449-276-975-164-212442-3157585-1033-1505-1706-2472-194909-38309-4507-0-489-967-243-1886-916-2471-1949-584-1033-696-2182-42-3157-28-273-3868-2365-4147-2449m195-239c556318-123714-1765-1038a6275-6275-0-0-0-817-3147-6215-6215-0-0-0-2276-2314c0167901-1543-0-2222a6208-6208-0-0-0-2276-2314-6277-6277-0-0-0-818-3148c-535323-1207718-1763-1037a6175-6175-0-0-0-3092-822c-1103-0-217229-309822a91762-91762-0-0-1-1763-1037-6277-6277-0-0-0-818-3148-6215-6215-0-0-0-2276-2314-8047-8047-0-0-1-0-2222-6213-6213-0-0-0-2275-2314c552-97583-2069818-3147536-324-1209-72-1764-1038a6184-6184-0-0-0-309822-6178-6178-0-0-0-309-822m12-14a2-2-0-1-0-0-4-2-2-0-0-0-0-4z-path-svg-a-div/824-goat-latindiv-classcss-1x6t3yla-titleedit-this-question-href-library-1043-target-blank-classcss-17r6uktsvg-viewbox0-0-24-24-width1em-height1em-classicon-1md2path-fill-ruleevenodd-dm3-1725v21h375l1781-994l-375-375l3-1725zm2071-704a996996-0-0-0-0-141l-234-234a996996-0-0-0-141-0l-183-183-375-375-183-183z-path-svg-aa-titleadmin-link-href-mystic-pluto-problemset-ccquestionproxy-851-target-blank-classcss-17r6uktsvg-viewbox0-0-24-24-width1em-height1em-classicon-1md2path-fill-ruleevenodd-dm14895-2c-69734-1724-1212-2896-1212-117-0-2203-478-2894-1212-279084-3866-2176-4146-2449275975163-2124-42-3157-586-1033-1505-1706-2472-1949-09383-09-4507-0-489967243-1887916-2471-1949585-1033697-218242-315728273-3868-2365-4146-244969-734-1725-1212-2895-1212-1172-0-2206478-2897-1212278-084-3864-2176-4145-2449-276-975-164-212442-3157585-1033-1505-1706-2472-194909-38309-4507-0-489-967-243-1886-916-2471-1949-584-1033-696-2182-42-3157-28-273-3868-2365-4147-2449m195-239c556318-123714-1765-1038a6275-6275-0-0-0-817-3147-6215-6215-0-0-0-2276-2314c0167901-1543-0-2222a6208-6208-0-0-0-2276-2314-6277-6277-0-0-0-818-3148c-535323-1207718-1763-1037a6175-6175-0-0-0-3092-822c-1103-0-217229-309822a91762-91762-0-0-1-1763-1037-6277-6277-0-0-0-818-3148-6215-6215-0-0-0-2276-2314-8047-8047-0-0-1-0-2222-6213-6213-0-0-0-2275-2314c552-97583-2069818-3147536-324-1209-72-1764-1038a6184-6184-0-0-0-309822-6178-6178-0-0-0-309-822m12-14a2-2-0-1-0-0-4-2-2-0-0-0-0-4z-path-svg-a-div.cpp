class Solution {
public:
    string toGoatLatin(string s) {
        vector<string> v;
        string ans = "" , t = "";
        for(int i = 0 ; i < s.size() ;i++){
            if(s[i] == ' ')
            {
                v.push_back(t);
                t = "";
            }
            else
                t += s[i];
        }
        v.push_back(t);
    int p = 1;
    for(auto x : v)
    {
        if(x[0] == 'a' or x[0] == 'e' or x[0] == 'i' or x[0] == 'o' or x[0] == 'u' or x[0] == 'A' or x[0] == 'E' or x[0] == 'I' or x[0] == 'O' or x[0] == 'U')
        {
            x += "ma";
        }
        else
        {
            x += x[0];
            string y = "";
            for(int i = 1 ; i < x.size() ;i++)
                y += x[i];
            x = y;
            x+="ma";
        }
            for(int i = 0; i  < p ;i++)
                x += 'a';
        p++;
        ans += x;
        ans += ' ';
    }
    ans.pop_back();
        return ans;
    }
};