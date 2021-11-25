class Solution {
public:
    //We will take 3 pointers, one for each number and put them at 1. Now we will check
    //product with smallest number and then increment it accordingly.
    int nthUglyNumber(int n) {
        vector<int>dp(n+1);
        dp[1] = 1;
        int p2 = 1;
        int p3 = 1;
        int p5 = 1;
        for(int i = 2;i <= n;i++)
        {
            int first = dp[p2]*2;
            int second = dp[p3]*3;
            int third = dp[p5]*5;
            if(first < second and first < third)
            {
                dp[i] = first;
                p2++;
            }
            else if(first == second and first < third)
            {
                dp[i] = first;
                p2++ , p3++;
            }
            else if(first == second and first == third)
            {
                dp[i] = first;
                p2++ , p3++ , p5++;
            }
            
            else if(first <= third and first < second)
            {
                dp[i] = first;
                p2++ , p5++;
            }
            
            else if(first > second and second < third)
            {
                dp[i] = second;
                p3++;
            }
            else if(second == third)
            {
                dp[i] = second;
                p3++ , p5++;
            }
            else
            {
                dp[i] = third;
                p5++;
            }
            //cout<<p2<<" "<<p3<<" "<<p5<<" "<<dp[i]<<"\n";
        }
       // for(auto x:dp)cout<<x<<" ";
        return dp[n];
        
        
    }
};
