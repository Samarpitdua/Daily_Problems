class Solution {
public:
    bool isVowel(char ch){
        return (ch == 'a' or ch == 'e' or ch == 'I' or ch == 'o' or ch == 'u' or ch == 'O' or ch == 'U' or ch == 'A' or ch == 'E' or ch == 'i');
    }
    bool halvesAreAlike(string s) {
        int n = s.size();
        int ct1 = 0 , ct2 = 0;
        for(int i = 0 , j = n / 2 ; j < n ;i++ , j++){
            if(isVowel(s[i]))
                ct1++;
            if(isVowel(s[j]))
                ct2++;
            
        }
        return ct1 == ct2;
    }
};