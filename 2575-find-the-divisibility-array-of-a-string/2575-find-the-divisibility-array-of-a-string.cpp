class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> ans;
        long long num = 0;
        
        for(auto x : word)
        {
            num = num * 10;
            num += (x - '0');
            num %= m;
            if(num % m == 0)
                ans.push_back(1);
            else
                ans.push_back(0);
        }
        return ans;
    }
};