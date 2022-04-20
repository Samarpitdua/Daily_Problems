class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = strs[0];
        int ct = s.size();
        for(int i = 1 ; i < strs.size() ; i++)
        {
            int temp = 0;
            for(int j = 0; j < strs[i].size() and j < strs[0].size(); j++)
            {
                if(temp >= ct)
                    break;
                if(strs[i][j] == strs[0][j])
                    temp++;
                else 
                    break;
            }
            ct = temp;
        }
        string ans ="";
        int i = 0;
        while(ct > 0)
        {
            ans += strs[0][i];
            i++;
            ct--;
        }
        return ans;
        
    }
};