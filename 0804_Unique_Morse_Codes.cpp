class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string>st;
        string s[26]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for(auto x:words)
        {
            string t="";
            for(auto y:x)
            {
                t+=s[y-'a'];
            }
            st.insert(t);
        }
              return st.size();
    }
};
