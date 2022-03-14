class Solution {
public:
    string simplifyPath(string path) {
        string ans = "" , temp;
        vector<string> ans2;
        stringstream ss(path);
        while(getline(ss,temp,'/'))
        {
            if (temp == "" || temp == ".")
                continue;
            if (temp == ".." && !ans2.empty()) 
                ans2.pop_back();
            else if (temp != "..") 
                ans2.push_back(temp);
        }
        for(auto x : ans2) ans += "/" + x;
        return ans.empty() ? "/" : ans;
        
    }
};