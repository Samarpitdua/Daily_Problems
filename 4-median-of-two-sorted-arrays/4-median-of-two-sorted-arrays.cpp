class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size() , n2 = nums2.size();
        if(n2 < n1)
            return findMedianSortedArrays( nums2 , nums1);
        int low = 0 , high = n1 ;
        while(low <= high)
        {
            int mid = low + (high - low) / 2 ;
            int mid2 = (n1 + n2 + 1) / 2 - mid ;
            int l1 , l2 ,r1, r2;
            if(mid == 0)
                l1 = INT_MIN;
            else
                l1 = nums1[mid - 1];
            if(mid2 == 0)
                l2 = INT_MIN;
            else
                l2 = nums2[mid2 - 1];
            
            if(mid == n1)
                r1 = INT_MAX;
            else
                r1 = nums1[mid];
            if(mid2 == n2)
                r2 = INT_MAX;
            else
                r2 = nums2[mid2];
            
            if(l1 <= r2 and l2 <= r1)
            {
                if((n1 + n2) % 2 == 0)
                    return (max(l1 , l2) + min(r1 , r2)) / 2.0 ;
                else
                    return max(l1 , l2);
            }
            else if(l1 > r2)
                high = mid - 1;
            else
                low = mid + 1;
            
        }
        return 0.0;
    }
};