class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        int ct = 0;
        for(int i = n - 1 ;i >= 0;i--)
        {
            if(s[i] == 'I' && s[i + 1] != 'X' && s[i + 1] != 'V')
                ct++;
            else if(s[i] == 'V')
                ct += 5;
            
            else if(s[i] == 'I' && (s[i + 1] == 'X' || s[i + 1] == 'V'))
                ct--;
            else if(s[i] == 'X'&&s[i+1] != 'L' && s[i + 1] != 'C')
                ct += 10;
            else if(s[i] == 'X' && (s[i + 1] == 'L' || s[i + 1] == 'C'))
            {
                    ct -= 10;
            }
            else if(s[i] == 'L')
            {
                    ct += 50;
            }
            
            else if(s[i] == 'C' && s[i + 1] != 'D' && s[i + 1] != 'M')
                ct += 100;
            else if(s[i] == 'C' && (s[i + 1] == 'D' || s[i + 1] == 'M'))
                ct -= 100;
            else if(s[i] == 'M')
                ct += 1000;
            else if(s[i] == 'D')
                ct += 500;
        }
        return ct;
        
    }
};