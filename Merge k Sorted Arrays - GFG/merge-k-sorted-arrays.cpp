//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++
#define pi pair<int , pair<int , int>>

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int> ans;
        priority_queue<pi , vector<pi> , greater<pi>> pq;
        int i = 0 , j = 0;
        for(int i = 0 ; i < K ; i++)
        {
            pq.push({arr[i][0] , {i , 0}});
        }
        while(!pq.empty())
        {
            auto temp = pq.top();
            ans.push_back(temp.first);
            if((temp.second.second + 1) < K)
            {
                pq.push({arr[temp.second.first][temp.second.second + 1] , {temp.second.first , temp.second.second + 1}});
            }
            pq.pop();
        }
        return ans;
        //code here
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends