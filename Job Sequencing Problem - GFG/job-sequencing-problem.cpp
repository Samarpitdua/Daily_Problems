// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/
#define pi pair<int , int>

class Solution 
{
    public:
    bool comparison(Job a,Job b)
{
    return(a.profit>b.profit);
}

    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        vector<int>v;
        priority_queue<pair<int , int>> pq;
        int maxi = 0;
        for(int i = 0 ; i < n ;i++)
        {
            pq.push({arr[i].profit , arr[i].dead});
            maxi = max(maxi , arr[i].dead);
        }
        vector<int>mp(maxi + 1 , 0);
        int ans = 0 , ct = 0 , temp3 = 0;
       // cout<<maxi<<" ";
        while(!pq.empty() and temp3 <= maxi)
        {
            int temp = pq.top().second;
                while(temp>0)
                {
                    if(!mp[temp])
                        {
                            mp[temp] = 1;
                            ct++;
                            ans += pq.top().first;
                            temp3++;
                            break;
                        }   
                        temp--;
                }
            pq.pop();
        }
        v.push_back(ct);
        v.push_back(ans);
        return v;
        // your code here
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends