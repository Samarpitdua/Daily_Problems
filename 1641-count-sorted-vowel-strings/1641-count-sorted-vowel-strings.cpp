class Solution {
public:
    int countVowelStrings(int n) {
       //return ((n+1)*(n+2)*(n+3)*(n+4))/24;
        int ans=0;
        for(int i=1;i<=(n+1);i++)
        {
            int sum=0;
            for(int j=1;j<=i;j++)
            {       sum+=j;
                ans+=sum;
        }
            
        }
        return ans;
        
    }
};