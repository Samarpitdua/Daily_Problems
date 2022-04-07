// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool isValid(int i , int j , vector<vector<int>> &m , int n)
    {
        return (i >= 0 and i < n and j >= 0 and j < n and m[i][j] != 0);
    }
    void findPath(vector<vector<int>> &m , int n , string temp , vector<string>& ans , int i , int j)
    {
        if(i == n - 1 and j == n - 1)
        {
            ans.push_back(temp);
            return;
        }
        if(isValid(i + 1 , j , m , n))
        {
            m[i + 1][j] = 0;
            findPath(m , n , temp + "D" , ans , i + 1 , j);
            m[i + 1][j] = 1;
        }
        if(isValid(i - 1 , j , m , n))
        {
            m[i - 1][j] = 0;
            findPath(m , n , temp + "U" , ans , i - 1 , j);    
            m[i - 1][j] = 1;
        }
        if(isValid(i , j + 1 , m , n))
        {
            m[i][j + 1] = 0;
            findPath(m , n , temp + "R" , ans , i , j + 1); 
            m[i][j + 1] = 1;
        }
        if(isValid(i , j - 1 , m , n))
        {
            m[i][j - 1] = 0;
            findPath(m , n , temp + "L" , ans , i , j - 1);  
            m[i][j - 1] = 1;
        }
        
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        string temp = "";
        if(m[0][0] == 0)
            return ans;
        m[0][0] = 0;
        findPath(m , n , temp , ans , 0 , 0);
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