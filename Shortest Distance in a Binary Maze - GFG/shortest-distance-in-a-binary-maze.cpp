//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  bool valid(int f , int s , vector<vector<int>> &grid)
    {
        int m = grid.size() , n =grid[0].size();
        if (f >= 0 and s >= 0 and f < m and s < n and grid[f][s] == 1)
        {
            grid[f][s] = 0;
            return true;
        }
        return false;
    }
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> dest) {
        int ct = 0;
        queue<pair<int , int>> q;
        q.push({source.first , source.second});
        if(source == dest)
        return 0;
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--){
            int f = q.front().first;
            int s = q.front().second;
            q.pop();
            if(f == dest.first and s == dest.second)
            {
                return ct;
            }
            if(valid(f  + 1, s , grid))
            {
                q.push({f + 1 , s});
            }
            if(valid(f , s + 1, grid))
            {
                q.push({f , s + 1});
            }
            if(valid(f - 1, s , grid))
            {
                q.push({f - 1 , s});
            }
            if(valid(f , s - 1, grid))
            {
                q.push({f, s - 1});
            }
            
            }
            
            
            ct++;
        }
        return -1;
        // code here
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends