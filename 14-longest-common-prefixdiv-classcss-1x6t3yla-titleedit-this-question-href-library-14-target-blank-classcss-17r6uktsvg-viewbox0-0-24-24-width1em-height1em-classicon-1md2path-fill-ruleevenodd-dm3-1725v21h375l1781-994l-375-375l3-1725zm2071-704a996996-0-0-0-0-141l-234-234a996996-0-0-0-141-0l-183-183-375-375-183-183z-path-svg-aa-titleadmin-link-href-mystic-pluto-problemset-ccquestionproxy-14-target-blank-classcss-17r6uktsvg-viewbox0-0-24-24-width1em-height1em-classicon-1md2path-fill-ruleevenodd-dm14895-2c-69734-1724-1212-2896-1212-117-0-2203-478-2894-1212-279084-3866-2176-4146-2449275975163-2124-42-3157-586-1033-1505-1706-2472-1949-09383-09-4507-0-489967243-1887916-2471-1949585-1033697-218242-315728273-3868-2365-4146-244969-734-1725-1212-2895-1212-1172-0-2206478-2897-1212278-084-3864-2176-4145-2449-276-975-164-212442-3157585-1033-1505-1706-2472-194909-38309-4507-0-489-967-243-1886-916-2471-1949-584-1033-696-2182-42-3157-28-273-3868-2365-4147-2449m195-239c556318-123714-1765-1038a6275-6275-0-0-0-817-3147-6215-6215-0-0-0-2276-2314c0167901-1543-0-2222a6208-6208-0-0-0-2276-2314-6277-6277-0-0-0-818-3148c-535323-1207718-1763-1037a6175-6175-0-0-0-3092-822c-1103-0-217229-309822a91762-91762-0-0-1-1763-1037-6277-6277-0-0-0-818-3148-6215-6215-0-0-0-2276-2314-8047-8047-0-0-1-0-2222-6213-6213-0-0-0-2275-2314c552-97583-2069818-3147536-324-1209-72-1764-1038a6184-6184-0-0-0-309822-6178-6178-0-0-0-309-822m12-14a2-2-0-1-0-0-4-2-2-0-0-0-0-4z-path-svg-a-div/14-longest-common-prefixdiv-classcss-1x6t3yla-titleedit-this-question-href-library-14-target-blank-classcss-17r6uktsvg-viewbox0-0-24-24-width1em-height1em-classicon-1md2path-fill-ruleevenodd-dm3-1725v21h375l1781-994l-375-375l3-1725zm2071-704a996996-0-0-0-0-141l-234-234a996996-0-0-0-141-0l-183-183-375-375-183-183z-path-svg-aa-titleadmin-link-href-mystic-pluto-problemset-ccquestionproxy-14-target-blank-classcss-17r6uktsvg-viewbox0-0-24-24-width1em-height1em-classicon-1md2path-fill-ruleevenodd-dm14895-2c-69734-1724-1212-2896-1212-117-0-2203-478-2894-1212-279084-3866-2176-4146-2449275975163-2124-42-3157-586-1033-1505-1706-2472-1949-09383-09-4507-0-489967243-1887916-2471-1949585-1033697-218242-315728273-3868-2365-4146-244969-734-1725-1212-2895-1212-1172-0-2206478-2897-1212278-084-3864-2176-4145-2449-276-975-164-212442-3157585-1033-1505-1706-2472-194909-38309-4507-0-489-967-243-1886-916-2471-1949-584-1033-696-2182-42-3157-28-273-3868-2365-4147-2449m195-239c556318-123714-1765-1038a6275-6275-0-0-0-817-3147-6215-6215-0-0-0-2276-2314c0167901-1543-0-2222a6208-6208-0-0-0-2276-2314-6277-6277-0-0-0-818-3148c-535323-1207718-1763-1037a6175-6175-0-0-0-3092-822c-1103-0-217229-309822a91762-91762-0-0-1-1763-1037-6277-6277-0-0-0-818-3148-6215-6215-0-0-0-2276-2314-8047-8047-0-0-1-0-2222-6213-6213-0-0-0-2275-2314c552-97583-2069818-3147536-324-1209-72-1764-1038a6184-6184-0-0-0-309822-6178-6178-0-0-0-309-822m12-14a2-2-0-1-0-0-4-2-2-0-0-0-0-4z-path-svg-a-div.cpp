class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        // int ct = 0;
        // string ans = "";
        // for(int ct = 0; ct < strs[0].size() ;ct++){  
        //     for(int j = 1 ; j < strs.size() ;j++){
        //     if(strs[j][ct] != strs[j - 1][ct])
        //         return ans; 
        //     }
        //     ans += strs[0][ct];
        // }
        // return ans;
        int n = str.size();
        if(n==0) return "";
        
        string ans  = "";
        sort(begin(str), end(str));
        string a = str[0];
        string b = str[n-1];
        
        for(int i=0; i<a.size(); i++){
            if(a[i]==b[i]){
                ans = ans + a[i];
            }
            else{
                break;
            }
        }
        
        return ans;
    }
};