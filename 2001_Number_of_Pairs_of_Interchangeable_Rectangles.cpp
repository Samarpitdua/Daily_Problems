class Solution {
public:
    long long multiply(long long a,
                            long long b,
                            long long mod)
{
    long long res = 0; // Initialize result
 
    // Update a if it is more than
    // or equal to mod
    a %= mod;
 
    while (b)
    {
        // If b is odd, add a with result
        if (b & 1)
            res = (res + a) % mod;
 
        // Here we assume that doing 2*a
        // doesn't cause overflow
        a = (2 * a) % mod;
 
        b >>= 1; // b = b / 2
    }
 
    return res;
}
    long long interchangeableRectangles(vector<vector<int>>& a) {
        map<double,int>mp;
        long long ans=0;
        for(int i=0;i<a.size();i++)
        {
            double k=a[i][0]/(double)a[i][1];
            //cout<<k<<" ";
            mp[k]++;
        }
        for(auto x:mp)
        {
            ans+=multiply(x.second,(x.second-1),10000000019)/2;
        }
        return ans;
        
    }
};
