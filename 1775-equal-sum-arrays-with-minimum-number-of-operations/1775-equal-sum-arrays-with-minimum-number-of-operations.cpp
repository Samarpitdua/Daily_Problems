class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int sum1 = 0 , sum2 = 0;
        for(auto x : nums1)
            sum1 += x;
        for(auto x : nums2)
            sum2 += x;
        if(sum1 == sum2)
            return 0;
        
        if(sum1 > sum2)
            swap(nums1 , nums2);
        sort(nums1.begin() , nums1.end());
        sort(nums2.begin() , nums2.end() , greater<int>());
        int diff = abs(sum1 - sum2) , ct = 0;
        int i = 0 , j = 0 ;
        for(;i < nums1.size() and j < nums2.size() ; )
        {
            if((6 - nums1[i]) > (nums2[j] - 1))
            {
                diff -= (6 - nums1[i]);
                nums1[i] = 6;
                i++;
            }
            else
            {
                diff -= (nums2[j] - 1);
                nums2[j] = 1;
                j++;
            }
            ct++;
            if(diff <= 0)
                return ct;
        }
        while(i < nums1.size())
        {
            diff -= (6 - nums1[i]);
            nums1[i] = 6;
            i++;
            ct++;
            if(diff <= 0)
                return ct;
        }
        while(j < nums2.size())
        {
            diff -= (nums2[j] - 1);
            nums2[j] = 1;
            j++;
            ct++;
            if(diff <= 0)
                return ct;
        }
        return -1;
    }
};