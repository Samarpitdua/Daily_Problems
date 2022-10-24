class Solution {
public:
    void solve(vector<string>& arr , int ind , int& maxi , string s , vector<int> freq)
    {
        if(ind == arr.size())
        {
            maxi = max(maxi , (int)s.size());
            return;
        }
        solve(arr , ind + 1, maxi , s , freq);
        int p = 0;
        for(int j = 0 ; j < arr[ind].size() ;j++)
        {
            if(freq[arr[ind][j] - 'a'] == 1)
            {
                p = 1;
                break;
            }
            else
                freq[arr[ind][j] - 'a'] = 1;
        }
        if(p == 0)
        {
            s += arr[ind];
            solve(arr , ind + 1 , maxi , s , freq);
        }
    }
    int maxLength(vector<string>& arr) {
        int maxi = 0;
        string s = "";
        vector<int> freq(26 , 0);
        solve(arr , 0 , maxi , s , freq);
        return maxi;
    }
};