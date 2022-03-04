class Solution {
public:
    double trimMean(vector<int>& arr) {
        int sz = arr.size() , ct = 0 , sum = 0;
        sort(arr.begin() , arr.end());
        for(int i = sz * 0.05 ; i < sz - sz * 0.05 ; i++)
            sum += arr[i] , ct++;
        return sum/double(ct);
        
        
        
    }
};