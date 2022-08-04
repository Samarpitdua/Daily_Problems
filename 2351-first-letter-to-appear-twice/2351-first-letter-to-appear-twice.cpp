class Solution {
public:
    char repeatedCharacter(string s) {
        int freq[26] = {0};
        for(auto x : s){
            freq[x - 'a']++;
            if(freq[x - 'a'] > 1)
                return x;
        }
        return ' ';
        
    }
};