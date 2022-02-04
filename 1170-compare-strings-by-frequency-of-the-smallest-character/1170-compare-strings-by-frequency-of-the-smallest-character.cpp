class Solution {
public:
    int solve(string s)
    {
        int freq[26]={0};
        for(auto x : s)
        {
            freq[x - 'a']++;
        }
        for(int i = 0 ; i < 26 ;i++)
        {
            if(freq[i] != 0)
                return freq[i];
        }
        return -1;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int n = words.size();
        vector<int> freq(n);
        for(int i = 0 ; i < words.size() ; i++)
            freq[i] = solve(words[i]);
        sort(freq.begin() , freq.end());
        vector<int> ans;
        for(int i = 0 ; i < queries.size() ;i++)
        {
            int temp = solve(queries[i]);
            int x = upper_bound(freq.begin() , freq.end() , temp) - freq.begin();
            ans.push_back(n - x);
        }
        return ans;
        
    }
};