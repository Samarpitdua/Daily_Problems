//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    queue<pair<int , int>> q;
	    int n = grid.size();
	    int m = grid[0].size();
	    vector<vector<int>> vis(n , vector<int>(m , 0));
	    for(int i = 0 ; i < n  ;i++)
	    {
	        for(int j = 0 ; j  < m ;j++)
	        {
	            if(grid[i][j] == 1)
	            {
	                vis[i][j] = 1;
	                grid[i][j] = 0;
	                q.push({i + 1 , j});
	                q.push({i , j - 1});
	                q.push({i - 1 , j});
	                q.push({i , j + 1});
	            }
	        }
	        
	    }
	    int ct = 0;
	    while(!q.empty())
	    {
	        ct++;
	        int sz = q.size();
	        for(int i = 0 ; i < sz ;i++){
	            int f = q.front().first;
	            int s = q.front().second;
	            q.pop();
	            if(f >= 0 and f < n and s >= 0 and s < m and vis[f][s] == 0)
	            {
	                grid[f][s] = ct;
	                vis[f][s] = 1;
	                q.push({f + 1 , s});
	                q.push({f , s - 1});
	                q.push({f - 1 , s});
	                q.push({f , s + 1});
	            }
	        }
	    }
	    return grid;
	    // Code here
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends