class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int  n = spaces.size();
        string t = "";
        int  j = 0;
        for(int i = 0 ; i < s.size() ; i++ )
        {
            if(j < n and i == spaces[j])
            {
                j++;
                t+= " ";
                t+=s[i];
            }
            else
                t += s[i];
        }
        return t ;
        
    }
};