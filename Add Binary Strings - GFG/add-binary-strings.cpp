//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	string addBinary(string A, string B)
	{
	    int m = A.size() , n = B.size();
	    int carry = 0;
	    string ans = "";
	    int i = m - 1 , j = n - 1 ;
	    while(i>=0 and j>=0)
	    {
	        if(carry){
    	        if(A[i] == '1' and B[j] == '1')
    	        {
    	            ans += '1';
    	        }
    	        else if(A[i] == '1' or B[j] == '1')
    	        {
    	            ans += '0';
    	        }
    	        else
    	        {
    	            ans += '1';
    	            carry = 0;
    	        }
    	        
	        }
	        else{
	            if(A[i] == '1' and B[j] == '1')
    	        {
    	            ans += '0';
    	            carry = 1;
    	        }
    	        else if(A[i] == '1' or B[j] == '1')
    	        {
    	            ans += '1';
    	        }
    	        else
    	        {
    	            ans += '0';
    	            carry = 0;
    	        }
	        }
	       // cout<<"hi1 ";
	        i-- , j--;
	    }
	    
	    while(i >= 0)
	    {
	        if(carry){
    	        if(A[i] == '1')
    	        {
    	            ans += '0';
    	        }
    	        else
    	        {
    	            ans += '1';
    	            carry = 0;
    	        }
	        }
	        else
	        {
	            if(A[i] == '1')
    	        {
    	            ans += '1';
    	        }
    	        else
    	        {
    	            ans += '0';
    	            carry = 0;
    	        }
	        }
	        i--;
	    }
	    while(j >= 0)
	    {
	        if(carry){
    	        if(B[j] == '1')
    	        {
    	            ans += '0';
    	        }
    	        else
    	        {
    	            ans += '1';
    	            carry = 0;
    	        }
	        }
	        else
	        {
	            if(B[j] == '1')
    	        {
    	            ans += '1';
    	        }
    	        else
    	        {
    	            ans += '0';
    	            carry = 0;
    	        }
	        }
	        j--;
	    }
	    if(carry)
	    ans += '1';
	   // cout<<ans<<" ";
	    i = ans.size() - 1;
	    while(1)
	    {
	        if(ans[i] == '0')
	        ans.pop_back();
	        else
	        break;
	        i--;
	    }
	    reverse(ans.begin() , ans.end());
	    
	    return ans;
	    // your code here
	}
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string A, B; cin >> A >> B;
		Solution ob;
		cout << ob.addBinary (A, B);
		cout << "\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends