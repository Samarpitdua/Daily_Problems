class Solution {
public:
    int merge(vector<int>& nums , int left , int right , int mid )
    {
        int ct = 0 , j = mid + 1;
        for(int i = left ; i <= mid ;i++)
        {
            while(j <= right and nums[i] > (2ll * nums[j]))
                j++;
            ct += (j - (mid + 1));
        }
        int k = left;
        int n1 = mid - left + 1;
        int n2 = right - mid;
        int arr1[n1] , arr2[n2];
        for(int i = 0 ; i < n1 ; i++)
            arr1[i] = nums[left + i];
        for(int i = 0 ; i < n2 ; i++)
            arr2[i] = nums[mid + i + 1];
        int i = 0;
        j = 0;
        while(i < n1 and j < n2)
        {
            if(arr1[i] < arr2[j])
                nums[k++] = arr1[i++];
            else
                nums[k++] = arr2[j++];
        }
        while(i < n1)
            nums[k++] = arr1[i++];
        while(i < n2)
            nums[k++] = arr2[i++];
        return ct;
    }
    int mergesort(vector<int>& nums,int left,int right)
    {
        int mid = 0 , ct = 0;
        if(left < right)
        {
            mid = (left + right) / 2;
            ct += mergesort(nums , left , mid);
            ct += mergesort(nums , mid + 1 , right);
            ct += merge(nums , left , right , mid);
        }
        return ct;
    }
    int reversePairs(vector<int>& nums) {
        return mergesort(nums , 0 , nums.size()-1);
        
    }
};