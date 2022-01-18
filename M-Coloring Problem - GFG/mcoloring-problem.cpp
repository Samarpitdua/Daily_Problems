// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool isSafe(bool graph[101][101] , int color , int vertex , vector<int>& colors)
{
        for(int k = 0 ; k < 101 ;k++)
        {
            if(graph[vertex][k] == 1 and colors[k] == color)
            return false;
        }
    
    return true;
}
bool solve(bool graph[101][101],vector<int>& colors ,int i , int m)
{
    if(i >= colors.size())
    return true;
    for(int color = 0 ; color <  m ;color++)
    {
        if(isSafe(graph , color , i , colors))
        {
            colors[i] = color;
            if(solve(graph , colors , i + 1 , m))
            return true;
            else
            colors[i] = -1;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int V)
{
    vector<int> colors(V , -1);
    bool ans = solve(graph , colors , 0 , m);
    return ans;
    // your code here
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends