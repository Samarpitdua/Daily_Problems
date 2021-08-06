class Solution {
public:
    //Simple Brute Force
    int count(int n)
    {
        int sum=0;
        while(n>0)
        {
            sum+=(n%10);
            n/=10;
        }
        return sum;
    }
    int countBalls(int low, int high) {
        map<int,int>mp;
        int mini=0;
        for(int i=low;i<=high;i++)
        {
            int p=count(i);
            mp[p]++;
        }
        for(auto x:mp)
        {
            if(x.second>mini)
            {
                mini=x.second;
            }
        }
        return mini;
    }
};
