class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size() , p = -1;
        if(n < 3)
            return false;
        if(arr[1] < arr[0])
            return false;
        for(int i = 1 ; i < n ;i++)
        {
            if(arr[i] == arr[i - 1])
                return false;
            if(arr[i] > arr[i - 1] and p == -1)
                continue;
            else if(p == -1)
                p = 1;
            else if(arr[i] < arr[i - 1] and p == 1)
                continue;
            else
                return false;
        }
        if(p == -1)
            return false;
        return true;
    }
};