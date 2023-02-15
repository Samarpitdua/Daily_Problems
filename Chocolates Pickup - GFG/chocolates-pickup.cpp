//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int find(vector<vector<int>>& grid , vector<vector<vector<int>>>& dp , int i , int j1 , int j2 , int n , int m)
  {
    //   cout<<"aya ";
      if(i == n)
      {
        //   cout<<"ok "; 
          return 0;
      }
      
      if(j1 < 0 or j2 < 0 or j1 >= m or j2 >= m )
      {
        //   cout<<"hi ";
          return 0;
      }
      if(dp[i][j1][j2] != -1)
      {
          return dp[i][j1][j2];
      }
    //   return 0;
      if(j1 == j2)
      {
          return dp[i][j1][j2] = grid[i][j1] + max({find(grid , dp , i + 1 , j1 , j2 , n , m) , find(grid , dp , i + 1 , j1 - 1, j2 , n , m) , find(grid , dp , i + 1 , j1 + 1, j2 , n , m) , find(grid , dp , i + 1 , j1 - 1, j2 - 1 , n , m)  , find(grid , dp , i + 1 , j1 + 1, j2 - 1 , n , m) , find(grid , dp , i + 1 , j1, j2 - 1 , n , m) , find(grid , dp , i + 1 , j1, j2 + 1 , n , m) , find(grid , dp , i + 1 , j1 - 1, j2 + 1 , n , m) , find(grid , dp , i + 1 , j1 + 1, j2 + 1 , n , m)});
      }
      else
      return dp[i][j1][j2] = grid[i][j1] + grid[i][j2] + max({find(grid , dp , i + 1 , j1 , j2 , n , m) , find(grid , dp , i + 1 , j1 - 1, j2 , n , m) , find(grid , dp , i + 1 , j1 + 1, j2 , n , m) , find(grid , dp , i + 1 , j1 - 1, j2 - 1 , n , m)  , find(grid , dp , i + 1 , j1 + 1, j2 - 1 , n , m) , find(grid , dp , i + 1 , j1, j2 - 1 , n , m) , find(grid , dp , i + 1 , j1, j2 + 1 , n , m) , find(grid , dp , i + 1 , j1 - 1, j2 + 1 , n , m) , find(grid , dp , i + 1 , j1 + 1, j2 + 1 , n , m)});
        // return dp[i][j1][j2] = grid[i][j1] + grid[i][j2] + find(grid , dp , i + 1 , j1 , j2 , n , m) + find(grid , dp , i + 1 , j1 - 1, j2 , n , m) + find(grid , dp , i + 1 , j1 + 1, j2 , n , m) + find(grid , dp , i + 1 , j1 - 1, j2 - 1 , n , m)  + find(grid , dp , i + 1 , j1 + 1, j2 - 1 , n , m) + find(grid , dp , i + 1 , j1, j2 - 1 , n , m) + find(grid , dp , i + 1 , j1, j2 + 1 , n , m) + find(grid , dp , i + 1 , j1 - 1, j2 + 1 , n , m) + find(grid , dp , i + 1 , j1 + 1, j2 + 1 , n , m);
  }
    int solve(int n, int m, vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(n , vector<vector<int>>(m , vector<int>(m , -1)));
        return find(grid , dp , 0 , 0 , m - 1 , n , m);
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
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends