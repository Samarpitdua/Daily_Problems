class Solution {
public:
    string truncateSentence(string s, int k) {
        int ct=0;
        vector<string>v;
        string t="";
        for(int i=0;i<s.size();i++)
        {
            if(ct==k)break;
            if(s[i]==' ')
            v.push_back(t),ct++;
            if(ct<k)
                t+=s[i];          
        }
        return t;
    }
};
