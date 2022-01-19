// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool isValid(int n , int row , int col ,vector<vector<int>>& m)
    {
        //cout<<row<<" "<<col<<endl;
        return (row < n and row >= 0 and col < n and col >= 0 and m[row][col]) ;
    }
    void solve(vector<vector<int>> &m , int n , string& s, vector<string>& ans , int rows , int cols)
    {
        if(m[rows][cols] == 0)
        return;
        if((rows == n - 1) and (cols == n - 1))
        {
          //  cout<<"hi";
            ans.push_back(s);
            return;
        }
                if(isValid(n , rows + 1 , cols , m ))
                {
                    m[rows][cols] = 0;
                    s += 'D';
                    solve(m , n , s , ans , rows + 1 , cols);
                    m[rows][cols] = 1;
                    s.pop_back();
                }
                if(isValid(n , rows , cols + 1 , m ))
                {
                    m[rows][cols] = 0;
                    s += 'R';
                    solve(m , n , s , ans , rows , cols + 1);
                    m[rows][cols] = 1;
                    s.pop_back();
                }
                if(isValid(n , rows - 1 , cols , m))
                {
                    m[rows][cols] = 0;
                    s += 'U';
                    solve(m , n , s , ans , rows - 1 , cols);
                    m[rows][cols] = 1;
                    s.pop_back();
                }
                if(isValid(n , rows , cols - 1 , m))
                {
                    m[rows][cols] = 0;
                    s += 'L';
                    solve(m , n , s , ans , rows , cols - 1);
                    m[rows][cols] = 1;
                    s.pop_back();
                }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        string s = "";
        solve(m , n , s , ans , 0 , 0);
        return ans;
        // Your code goes here
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends