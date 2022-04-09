// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool isValid(bool graph[101][101] , int color , int ind  , vector<int>& vertice)
{
    for(int i=0;i<101;i++)
    {
        if(graph[ind][i] == 1 and vertice[i] == color)
            return false;
    }
    return true;
}
bool solve(bool graph[101][101] , int m , vector<int>& vertice , int ind)
{
    if(ind >= vertice.size())
        return true;
    for(int color = 0 ; color < m ;color++)
    {
        if(isValid(graph , color , ind , vertice))
        {
            vertice[ind] = color;
            if(solve(graph , m , vertice , ind + 1))
                return true;
            vertice[ind] = -1;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int V)
{
    vector<int> vertice(V , -1);
    return solve(graph , m , vertice , 0);
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