// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& in) {
        int n = in.size();
        vector<vector<int>> ans;
        sort(in.begin() , in.end());
        vector<int> temp(2);
        int p = 0;
        for(int i = 1 ;i < in.size() ;i++){
            if(in[i][0] > in[i - 1][1]){
                ans.push_back(in[i - 1]);
                p = 0;
                continue;
            }
            else
            {
                p = 1;
                in[i][0] = in[i - 1][0];
                in[i][1] = max(in[i - 1][1] , in[i][1]);
            }
        }
        {
            ans.push_back(in[n - 1]);
        }
        return ans;
         // Code here
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends