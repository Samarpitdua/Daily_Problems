// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/
bool comp(Item a , Item b)
{
    double temp1 = a.value / (double)a.weight;
    double temp2 = b.value / (double)b.weight;
    return temp1 > temp2;
    
}
class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        double ans = 0;
        sort(arr , arr + n , comp);
        for(int i = 0 ; i < n ;i++)
        {
            if(W == 0)
                break;
            if(arr[i].weight <= W)
            {
                ans += arr[i].value;
                W -= arr[i].weight;
            }
            else
            {
                double forOne = arr[i].value / (double)arr[i].weight;
                ans += (W * forOne);
                break;
            }
        }
        return ans;
        // Your code here
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends