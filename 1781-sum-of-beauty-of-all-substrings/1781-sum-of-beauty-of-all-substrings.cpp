class Solution {
public:
    int beautySum(string s) {
        int freq[26]= {0};
        int n = s.size();
        int ans = 0;
        for(int i = 0 ; i < n ;i++)
        {
            string temp = "";
            int freq[26] = {0};
            for(int j = i ; j < n ; j++)
            {
                temp += s[j];
                freq[s[j] - 'a']++;
                int maxi = 0 , mini = INT_MAX;
                for(int i = 0 ; i < 26 ; i++)
                {
                    maxi = max(maxi , freq[i]);
                    if(freq[i] > 0 and freq[i] < mini)
                        mini = freq[i];
                }
                ans += (maxi - mini);
                
            }
        }
        return ans;
            
    }
};