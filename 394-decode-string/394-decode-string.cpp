class Solution {
public:
    string decodesString(string s , int& i) {
        string ans = "";
        
        while (i < s.size() && s[i] != ']') {
            
            if (!isdigit(s[i]))
                ans += s[i++];
            else 
            {
                int n = 0;
                while (i < s.size() and isdigit(s[i]))
                    n = n * 10 + s[i++] - '0';
                    
                i++; // '['
                string t = decodesString(s, i);
                i++; // ']'
                
                while (n-- > 0)
                    ans += t;
            }
        }
        
        return ans;
    }
    string decodeString(string s){
        int i = 0;
        return decodesString(s , i);
    }
};