class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin() , nums.end());
        if(nums.size()<4)
            return ans;
        for(int i = 0 ; i < n - 2 ; i++)
        {
            
            for(int j = i + 1 ; j < n - 1 ; j++)
            {
               long long int sum = nums[j] + nums[i];
                int k = j + 1 , l = n - 1; 
                while(k < l)
                {
                    long long int sum2 = nums[k] + nums[l] + sum;
                    if(sum2 > target)
                        l--;
                    else if(sum2 < target)
                        k++;
                    else
                    {
                        vector<int> temp(4);
                        temp[0] = nums[i];
                        temp[1] = nums[j];
                        temp[2] = nums[k];
                        temp[3] = nums[l];
                        ans.push_back(temp);
                        while(k < l and nums[k] == temp[2])
                            k++;
                        while(l > k and nums[l] == temp[3])
                            l--;
                    }
                }
                while(j < n - 1 and nums[j] == nums[j + 1])
                    j++;
            }
            while(i < n - 1 and nums[i] == nums[i + 1])
                i++;
        }
        
        return ans;
        
    }
};