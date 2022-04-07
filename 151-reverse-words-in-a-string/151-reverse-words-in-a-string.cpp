class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        vector <string> v;
        string temp;
        
        while(ss >> temp)
            v.push_back(temp);
            
        string ans = "";
        reverse(v.begin() , v.end());
        
        for(auto x : v)
        {
            ans += x;
            ans += ' ';
        }
        
        int n = ans.size();
        ans.pop_back();
        return ans;
    }
};