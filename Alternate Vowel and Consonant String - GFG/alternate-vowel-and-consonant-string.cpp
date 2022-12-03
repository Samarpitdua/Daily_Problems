//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    string helper(vector<int> c, vector<int> v, int n){
         string ans = "";
        int p = 0, q = 0;
        for(int i = 0; i < n; i ++){
            int sz = ans.size();
            if(sz % 2 == 0){
                while(v[p] == 0){
                    p++;
                }
                ans += (p + 'a');
                v[p] --;
            }
            else{
                while(c[q] == 0){
                    q++;
                }
                ans += (q + 'a');
                c[q]--;
            }
        }
        return ans;
    }
    
    string rearrange (string s, int n)
    {
        // your code here
        vector<int> v(26,0), c(26,0);
        int count1 = 0, count2 = 0;
        for(auto it : s){
            if(it == 'a' || it == 'e' || it == 'i' || it == 'o' || it == 'u'){
                v[it -'a']++;
                count1 ++;
            }
            else{
                c[it-'a']++;
                count2 ++;
            }
        }
        if(abs(count1 - count2) > 1) return "-1";
        string ans;
        if(count1 >= count2)
          ans = helper(c,v,n);
        else{
            ans = helper(v,c,n);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		Solution ob;
		cout << ob.rearrange (s, n) << endl;
	}
}
// Contributed By: Pranay Bansal

// } Driver Code Ends