class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
         int n=shifts.size();
        string s1="";
        if(n==0)
            return s1;
        int sum=shifts[n-1];
        for(int i=shifts.size()-2;i>=0;i--)
        {
            shifts[i]+=sum;
            shifts[i]%=26;
            sum=shifts[i];   
        }
        for(int i=0;i<n;i++)
        {
            int ct=s[i]-'a';
            int temp=(ct+shifts[i])%26;
            s1+=char(97+temp);
        }
        return s1;
        
    }
};
