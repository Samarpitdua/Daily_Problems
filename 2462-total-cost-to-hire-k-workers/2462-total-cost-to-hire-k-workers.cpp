#define pi pair<int , int>
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int c) {
        priority_queue<pi , vector<pi> , greater<pi>> pql , pqr;
        long long ans = 0;
        int n = costs.size();
        int ct = 0 , i = 0 , j = n - 1;
        while(ct < k)
        {
            while(pql.size() < c and i <= j)
            {
                pql.push({costs[i] , i});
                i++;
            }
            while(pqr.size() < c and i <= j)
            {
                pqr.push({costs[j] , j});
                j--;
            }
            // cout<<i<<" "<<j<<endl;
            if(pqr.empty())
            {
                ans += pql.top().first;
                pql.pop();
            }
            else if(pql.empty())
            {
                ans += pqr.top().first;
                pqr.pop();
            }
            else if(pql.top().first <= pqr.top().first)
            {
                ans += pql.top().first;
                pql.pop();
            }
            else
            {
                ans += pqr.top().first;
                pqr.pop();
            }
            cout<<ans<<" ";
            ct++;
            
        }
        return ans;
    }
};