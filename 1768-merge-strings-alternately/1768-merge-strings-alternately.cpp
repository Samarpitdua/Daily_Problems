class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans ="";
        int i = 0 , j = 0 , m = word1.size() , n = word2.size();
        while(i < m and j < n){
            ans += word1[i++];
            ans += word2[j++];
        }
        while(i < m){
            ans += word1[i++];
        }
        while(j < n){
            ans += word2[j++];
        }
        return ans;
    }
};