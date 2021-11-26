class Solution {
public:
    int minSteps(int n) {
        //Observation: Every prime number has n steps
        //Every other number will have sum of its prime factors
        int ans=0;
        int m=n;
        for(int i=2;i<=m;i++)
        {
            while(n%i==0)
            {
                ans+=i;
                n/=i;
            }
        }
        if(n!=1)
            return n;
        else
            return ans;
        
    }
};
