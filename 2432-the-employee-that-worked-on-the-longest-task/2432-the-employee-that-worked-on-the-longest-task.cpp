class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int st = 0;
        int ans = 0 , maxi = INT_MIN;
        for(auto x : logs)
        {
            int per = x[0];
            int end = x[1] - st;
            st = x[1];
            if(end > maxi)
            {
                ans = per;
                maxi = end;
            }
            else if(end == maxi and per < ans)
            {
                ans = per;
            }
        }
        
        return ans;
    }
};