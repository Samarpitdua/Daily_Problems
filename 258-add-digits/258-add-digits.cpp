class Solution {
public:
    int addDigits(int num) {
        string s = to_string(num);
        while(s.size() > 1)
        {
            long long int ans = 0;
            for(auto x : s)
            {
                ans += (x - '0');
            }
            s = to_string(ans);
        }
        long long int ans = stoi(s);
        return ans;
        
    }
};