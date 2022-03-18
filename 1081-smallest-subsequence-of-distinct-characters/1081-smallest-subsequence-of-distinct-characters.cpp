class Solution {
public:
    string smallestSubsequence(string s) {
        string ans = "";
        int last_add[26] = {0} , n = s.size();
        bool already_add[26] = {false};
        
        for(int i = 0 ; i < n ; i++)
            last_add[s[i] - 'a'] = i;
        
        for(int i = 0 ; i < n ;i++)
        {
            if(already_add[s[i] - 'a'])
                continue;
            
            while(!ans.empty() and (ans.back() > s[i]) and last_add[ans.back() - 'a'] > i)
            {
                already_add[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            
            ans.push_back(s[i]);
            already_add[s[i] - 'a'] = true;
        }
        return ans;
        
    }
};