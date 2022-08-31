class Solution {
public:
    int percentageLetter(string s, char letter) {
        int ct = 0;
        for(auto x : s)
        {
            if(x == letter)
                ct++;
        }
        return (ct * 100) / s.size();
    }
};