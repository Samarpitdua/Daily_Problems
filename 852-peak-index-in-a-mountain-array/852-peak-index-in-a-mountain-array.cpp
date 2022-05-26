class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0 , high = arr.size()-1 , n = arr.size();
       while(low <= high)
       {
           int mid = low + (high - low) / 2;
           if(mid == 0)
           {
               low = mid + 1;
               continue;
           }
           else if(mid == n - 1)
           {
               high = mid - 1;
                continue;
           }
           if(arr[mid] > arr[mid - 1] and arr[mid] > arr[mid + 1])
           {
               return mid;
           }
           else if(arr[mid] > arr[mid - 1])
           {
               low = mid + 1;
           }
           else
               high = mid - 1;
       }
        return 0;
    }
};