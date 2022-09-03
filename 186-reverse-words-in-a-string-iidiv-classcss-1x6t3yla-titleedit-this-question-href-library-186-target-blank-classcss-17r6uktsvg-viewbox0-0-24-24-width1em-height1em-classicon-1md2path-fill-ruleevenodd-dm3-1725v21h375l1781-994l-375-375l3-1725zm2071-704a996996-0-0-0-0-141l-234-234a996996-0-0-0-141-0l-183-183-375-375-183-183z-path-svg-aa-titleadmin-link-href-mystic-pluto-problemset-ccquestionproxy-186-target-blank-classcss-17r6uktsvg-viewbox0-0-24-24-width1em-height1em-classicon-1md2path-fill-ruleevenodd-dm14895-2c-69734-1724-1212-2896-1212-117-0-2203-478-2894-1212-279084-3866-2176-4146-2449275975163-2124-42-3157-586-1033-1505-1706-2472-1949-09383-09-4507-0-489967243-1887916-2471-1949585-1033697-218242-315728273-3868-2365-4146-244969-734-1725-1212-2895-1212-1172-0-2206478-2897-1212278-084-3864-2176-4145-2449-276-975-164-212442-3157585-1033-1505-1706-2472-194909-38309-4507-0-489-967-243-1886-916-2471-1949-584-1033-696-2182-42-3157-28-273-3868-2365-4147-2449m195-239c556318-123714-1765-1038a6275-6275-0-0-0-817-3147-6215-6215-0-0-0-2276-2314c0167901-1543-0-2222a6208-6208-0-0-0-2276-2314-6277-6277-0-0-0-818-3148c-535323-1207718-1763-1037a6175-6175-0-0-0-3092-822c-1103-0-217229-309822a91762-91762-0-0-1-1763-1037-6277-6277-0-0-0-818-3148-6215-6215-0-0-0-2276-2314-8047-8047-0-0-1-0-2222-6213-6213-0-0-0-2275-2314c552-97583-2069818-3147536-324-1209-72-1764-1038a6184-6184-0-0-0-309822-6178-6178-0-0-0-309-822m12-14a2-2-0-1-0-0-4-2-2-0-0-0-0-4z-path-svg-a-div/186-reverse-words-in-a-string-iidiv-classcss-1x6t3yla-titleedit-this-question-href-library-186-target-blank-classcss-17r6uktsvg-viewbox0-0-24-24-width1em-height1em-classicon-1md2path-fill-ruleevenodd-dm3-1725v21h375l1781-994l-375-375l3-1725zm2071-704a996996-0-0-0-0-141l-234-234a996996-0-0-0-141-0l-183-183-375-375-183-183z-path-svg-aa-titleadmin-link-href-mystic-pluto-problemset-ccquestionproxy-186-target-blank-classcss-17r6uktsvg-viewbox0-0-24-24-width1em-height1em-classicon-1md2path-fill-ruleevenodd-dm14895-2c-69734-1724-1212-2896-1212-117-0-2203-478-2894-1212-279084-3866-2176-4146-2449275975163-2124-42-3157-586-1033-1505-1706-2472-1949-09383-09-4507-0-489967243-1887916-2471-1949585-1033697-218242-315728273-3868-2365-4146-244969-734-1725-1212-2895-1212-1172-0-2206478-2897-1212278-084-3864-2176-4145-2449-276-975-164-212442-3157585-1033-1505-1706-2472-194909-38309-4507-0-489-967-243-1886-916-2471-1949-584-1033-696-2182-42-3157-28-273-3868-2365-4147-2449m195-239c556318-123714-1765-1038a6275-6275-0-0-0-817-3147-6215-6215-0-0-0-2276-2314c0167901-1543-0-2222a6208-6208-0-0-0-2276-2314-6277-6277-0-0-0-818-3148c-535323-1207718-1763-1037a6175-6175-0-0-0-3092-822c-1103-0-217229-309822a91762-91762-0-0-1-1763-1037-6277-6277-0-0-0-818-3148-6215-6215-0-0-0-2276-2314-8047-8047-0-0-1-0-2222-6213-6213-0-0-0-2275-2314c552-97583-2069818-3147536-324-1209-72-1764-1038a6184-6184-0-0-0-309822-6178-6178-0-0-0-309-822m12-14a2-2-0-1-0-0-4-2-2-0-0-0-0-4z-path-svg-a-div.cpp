class Solution {
public:
    void reverseWords(vector<char>& s) {
        vector<string> ans;
        string t = "";
        for(int i = 0 ; i < s.size() ;i++){
            if(s[i] == ' ')
                ans.push_back(t) , t = "";
            else
                t += s[i];
        }
        ans.push_back(t) , t = "";
        reverse(ans.begin() , ans.end());
        int j = 0;
        for(int i = 0; i < ans.size() ;i++)
        {
            for(auto y : ans[i])
            {
                s[j++] = y;
            }
            if(i != ans.size() - 1)
            s[j++] = ' ';
        }
        
        
    }
};