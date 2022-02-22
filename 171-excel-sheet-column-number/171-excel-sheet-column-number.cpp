class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0 , ct = 0 , n = columnTitle.size();
        
        for(int i = 0 ; i < columnTitle.size() ;i++)
        {
            ans *= 26;
            ans += (columnTitle[i] - 'A' + 1);
           
        }
        return ans ;
    }
};