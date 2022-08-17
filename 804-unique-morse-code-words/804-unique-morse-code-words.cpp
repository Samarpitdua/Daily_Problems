class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
       string a[27] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> st;
        for(auto x : words){
            string ans = "";
            for(auto y : x){
                ans += a[y - 'a'];
            }
            st.insert(ans);
        }
        return st.size();
    }
};