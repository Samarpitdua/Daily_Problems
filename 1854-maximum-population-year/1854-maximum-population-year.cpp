class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
       // sort(logs.begin() , logs.end());
        int n = logs.size();
        map<int , int> mp;
        for(int i = 0 ; i < n ;i++)
        {
            for(int j = logs[i][0] ; j < logs[i][1] ;j++)
            {
                mp[j]++;
            }
        }
        int ans = 0;
        int toreturn;
        for(auto x : mp)
        {
            if(x.second > ans)
            {
                ans = x.second;
                toreturn = x.first;
            }
        }
        return toreturn;
    }
};