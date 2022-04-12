// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    void findSmallerLeft(vector<int>& left , int a[] , int n)
{
	stack<int> st;
	for(int i = 0 ; i < n ;i++)
	{
		while(!st.empty() and a[st.top()] >= a[i])
			st.pop();
		if(st.empty())
			left.push_back(-1);
		else
			left.push_back(st.top());
		st.push(i);
	}
}
void findSmallerRight(vector<int>& right , int a[] , int n)
{
	stack<int> st;
	for(int i = n - 1 ; i >= 0 ;i--)
	{
		while(!st.empty() and a[st.top()] >= a[i])
			st.pop();
		if(st.empty())
			right.push_back(n);
		else
			right.push_back(st.top());
		st.push(i);
	}
	reverse(right.begin() , right.end());
}
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int a[], int n)
    {
        vector<int> ans(n + 1 , INT_MIN);
    	vector<int> left , right;
    	
    	findSmallerLeft(left , a , n);
    	findSmallerRight(right , a, n);
    	
    	for(int i = 0 ; i < n ;i++)
    	{
    		int lengthOfWindow = (right[i] - left[i] - 1);
    		ans[lengthOfWindow] = max(ans[lengthOfWindow] , a[i]);
    	}
    	for(int i = n - 1 ; i >= 1 ;i--)
    	{
    		ans[i] = max(ans[i] , ans[i + 1]);
    	}
    	ans.erase(ans.begin());
    	return ans;
        // Your code here
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends