class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int ct = 0;
        string ans = "";
        for(int ct = 0; ct < strs[0].size() ;ct++){  
            for(int j = 1 ; j < strs.size() ;j++){
            if(strs[j][ct] != strs[j - 1][ct])
                return ans; 
            }
            ans += strs[0][ct];
        }
        return ans;
    }
};