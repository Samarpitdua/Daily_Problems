class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int ans = 0;
        map<int , int> mp;
        for(auto x : tasks)
            mp[x]++;
        for(auto x : mp)
        {
            int temp = x.second;
            if(temp == 1)
                return -1;
            while(x.second > 4)
            {
                x.second -= 3;
                ans++;
            }
            if(x.second == 4)
                ans += 2;
            else
                ans += 1;
        }
        return ans;
        
    }
};