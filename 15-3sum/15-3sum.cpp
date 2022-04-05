class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin() , nums.end());
        if(n < 3)
            return ans;
        for(int i = 0 ; i < n - 2 ; i++)
        {
            while(i < n - 2 and i != 0 and nums[i] == nums[i - 1])
                i++;
            if(i >= n - 2)
                break;
            int j = i + 1 , k = n - 1;
             int sum = nums[i];
            while(j < k)
            {
                int sum2 = nums[j] + nums[k];
               
                if((sum + sum2) == 0)
                {
                   // cout<<i<<" "<<j<<" "<<k<<endl;
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    ans.push_back(temp);
                    
                    int x = nums[j] , y = nums[k];
                    while(j < k and nums[j] == x)
                            j++;
                    while(j < k and nums[k] == y)
                        k--;
                }
                else if((sum2 + sum) < 0)
                    j++;
                else
                    k--;
            }
        }
        return ans;
    }
};
