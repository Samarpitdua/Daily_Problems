class Solution {
public:
    int mySqrt(int x) {
        long long int high = x , low = 1;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(mid == x / mid)
                return mid;
            else if(mid > x / mid)
                high = mid - 1;
            else
            {
                // ans = low;
                low = mid + 1;
            }
        }
        return min(low , high);
    }
};