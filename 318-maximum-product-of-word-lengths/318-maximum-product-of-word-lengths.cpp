class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans = 0 , n = words.size();
        vector<vector<int>> freq(n , vector<int>(26 , 0));
        for(int i = 0 ; i < n ;i++)
        {
            for(auto x : words[i])
            {
                freq[i][x - 'a']++;
            }
        }
        for(int i = 0 ; i < n ;i++)
        {
            for(int j = i + 1 ; j < n ;j++)
            {
                int p = 0;
                for(int k = 0 ; k < 26 ;k++)
                {
                    if(freq[i][k] > 0 and freq[j][k] > 0)
                    {
                        p = 1;
                        break;
                    }
                }
                if(p==0)
                {
                    int temp1 = words[i].size() , temp2 = words[j].size();
                    ans = max(ans , temp1 * temp2);
                }
            }
        }
        return ans;
    }
};