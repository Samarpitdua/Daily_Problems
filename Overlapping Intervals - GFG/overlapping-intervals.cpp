// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end());
        int start = intervals[0][0];
        int finish = intervals[0][1];
        int p = -1;
        vector<vector<int>> ans;
        for(auto x : intervals)
        {
            if(p == -1)
            {
                p = 1;
                continue;
            }
            if(x[0] <= finish)
            {
                finish = max(x[1] , finish);
            }
            else
            {
                ans.push_back({start , finish});
                start = x[0];
                finish = x[1];
            }
        }
        ans.push_back({start , finish});
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