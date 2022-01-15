// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string s){
        int maxi = 0;
        int a[26] = {0};
        int n = s.size();
        for(int i = 0 , j = 0; i < n ;i++)
        {
            a[s[i] - 'a']++;
            if(a[s[i] - 'a'] > 1)
            {
                while(s[j] != s[i])
                {
                    a[s[j] - 'a']--;
                    j++;
                }
                a[s[j] - 'a']--;
                j++;
            }
            maxi = max(maxi , i - j + 1);
        }
        return maxi;
        //code
        
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}  // } Driver Code Ends