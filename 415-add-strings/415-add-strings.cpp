class Solution {
public:
    string addStrings(string num1, string num2) {
        int n=num1.size();
        int m=num2.size();
        int carry=0,sum=0;
        string t="";
        int i=n-1,j=m-1;
        for(;i>=0 and j>=0;i--,j--)
        {
            sum=0;
            if(carry)
            {
                int a=num1[i]-'0';
                int b=num2[j]-'0';
                sum=a+b;
                if(sum>=9)
                {
                    sum+=1;
                    int bot=(sum%10);
                    t+=(bot+'0');
                    carry=1;
                }
                else
                {
                    sum++;
                    t+=(sum+'0');
                    carry=0;
                }
            }
            else
            {
                int a=num1[i]-'0';
                int b=num2[j]-'0';
                sum=a+b;
                if(sum>9)
                {
                    //sum+=carry;
                    t+=((sum%10)+'0');
                    carry=1;
                }
                else
                {
                    //sum++;
                    t+=(sum+'0');
                    carry=0;
                }
            }
        }
        //cout<<i<<" "<<j<<endl;
        while(i>=0)
        {
            int a=num1[i]-'0';
            if(carry){
                a++;
                if(a<10)
                    carry=0;
                t+=(a%10+'0');
            }
            else
            {
                t+=((a%10)+'0');
                if(a>9)
                carry=1;
            }
            i--;
        }
        
        
        
        
        while(j>=0)
        {
            int a=num2[j]-'0';
            if(carry){
                a++;
                if(a<10)
                    carry=0;
                t+=((a%10)+'0');
            }
            else
            {
                t+=((a%10)+'0');
                if(a>9)
                carry=1;
            }
            j--;
        }
        if(carry)
            t+='1';
        reverse(t.begin(),t.end());
        return t;
        
    }
};