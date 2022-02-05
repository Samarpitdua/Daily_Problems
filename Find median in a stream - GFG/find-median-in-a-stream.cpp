// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    
    priority_queue<double> left;
    priority_queue<double , vector<double> , greater<double> > right; 
    //Function to insert heap.
    void insertHeap(int &num)
    {
         if(left.empty())
            left.push(num);
        else
        {
            if(num > left.top())
                right.push(num);
            else
                left.push(num);
        }
        if((left.size()) > right.size() + 1)
        {
            int temp = left.top();
            left.pop();
            right.push(temp);
        }
        else if((right.size()) > left.size() + 1)
        {
            int temp = right.top();
            right.pop();
            left.push(temp);
        }
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(left.size() > right.size())
            return left.top();
        else if(left.size() < right.size())
            return right.top();
        else
        {
            double ans = (left.top() + right.top()) / double(2);
            return ans;
        }

    }
};


// { Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}  // } Driver Code Ends