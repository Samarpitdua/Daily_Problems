class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int ans = INT_MAX;
        vector<vector<int>> total;
        sort(arr.begin() , arr.end());
        for( int i = 1 ; i < arr.size() ; i++ )
        {
            int diff = arr[i] - arr[i-1];
            if(diff < ans)
                ans = diff;
        }
        for(int i = 0 ; i < arr.size() - 1 ;i++)
        {
            if(arr[i+1] - arr[i] == ans)
                total.push_back({arr[i] , arr[i+1]});
        }
        return total;
    }
};
