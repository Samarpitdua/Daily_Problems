class Solution {
public:
    vector<int> closestDivisors(int num) {
        int n=num+1;
        int m=num+2;
        vector<int>v(2);
        int ans=INT_MAX;
        for(int i=1;i*i<=n;i++)
        {
            if(n%i==0)
            {
               int temp=(n/i)-i;
                if(temp<ans)
                {
                    v[0]=i;
                    v[1]=n/i;
                    ans=temp;
                }
            }
        }
        for(int i=1;i*i<=m;i++)
        {
            
            if(m%i==0)
            {
               int temp=(m/i)-i;
                if(temp<ans)
                {
                    v[0]=i;
                    v[1]=m/i;
                    ans=temp;
                }
            }
        }
        return v;
        
    }
};
