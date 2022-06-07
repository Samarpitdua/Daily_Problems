class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int gap = ceil((m + n) / (double)2);
        for(int i = m , j = 0; i < nums1.size() ;i++)
        {
            nums1[i] = nums2[j++];
        }
        while(gap)
        {
            for(int i = 0 , j = gap ; j < nums1.size() ;i++ ,j++)
            {
                if(nums1[i] > nums1[j])
                    swap(nums1[i] , nums1[j]);
            }
            if(gap == 1)
                break;
            gap = (gap + 1) / 2;
            
        }
    }
};