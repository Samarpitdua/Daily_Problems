class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        string t = "";
        vector<string> ans;
        for(auto x : s)
        {
            t += x;
            if(t.size() == k)
            {
                ans.push_back(t);
                t = "";
            }
        }
        if(t != ""){
        while(t.size() != k)
        {
            t += fill;
        }
        }
        if(t!="")
        ans.push_back(t);
        return ans;
        
    }
};