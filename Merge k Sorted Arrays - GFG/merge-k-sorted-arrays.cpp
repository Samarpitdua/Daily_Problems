// { Driver Code Starts
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

#define pii pair<int , pair<int , int>>
class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        vector<int> ans;
        priority_queue<pii , vector<pii> , greater<pii>> pq;
        for(int i = 0 ; i < k ;i++){
            pq.push({arr[i][0] , {i , 0}});
        }
        while(1)
        {
            if(ans.size() == k * k)
                break;
            auto temp = pq.top();
            pq.pop();
            int f = temp.first;
            int sf = temp.second.first;
            int ss = temp.second.second;
            ans.push_back(f);
            if(ss + 1 < k)
            {
                pq.push({arr[sf][ss + 1] , {sf , ss + 1}});
            }
            
        }
        return ans;
        return ans;
        //code here
    }
};

// { Driver Code Starts.

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