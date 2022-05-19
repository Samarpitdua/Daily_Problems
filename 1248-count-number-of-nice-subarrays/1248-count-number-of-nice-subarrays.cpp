class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int ct = 0 , ans = 0 , start = 0 , end = 0;
        for(int i = 0 , j = 0 ; i < n ;i++)
        {
            if(nums[i] & 1)
            {
                ct++;
            }
            if(ct == k )
            {
                while(1)
                {
                    if(nums[j]%2==0)
                    {
                        j++;
                        start++;
                    }
                    else
                    {
                        start++;
                        break;
                    }
                }
                j++;
                i++;
                while(i < n and nums[i] % 2 == 0)
                {
                    i++;
                    end++;
                }
                end++;
                ans += (start * end);
                ct--;
                if(i != n)
                    i--;
                start = 0 , end = 0; 
            }
        }
        return ans;
    }
};