class Solution {
public:
    int minTimeToType(string s) {
        int ct=0;
        int a=0;
        for(int i=0;i<s.size();i++)
        {
            
            int temp=s[i]-'a';
            //cout<<temp<<" ";
            int diff1=abs(a-temp);
            int diff2=abs(26-a+temp);
            int diff3=abs(26-temp+a);
            ct+=min({diff1,diff2,diff3});
            a=temp;
           // cout<<ct<<"\n";
        }
        return (ct+s.size());
        
    }
};
