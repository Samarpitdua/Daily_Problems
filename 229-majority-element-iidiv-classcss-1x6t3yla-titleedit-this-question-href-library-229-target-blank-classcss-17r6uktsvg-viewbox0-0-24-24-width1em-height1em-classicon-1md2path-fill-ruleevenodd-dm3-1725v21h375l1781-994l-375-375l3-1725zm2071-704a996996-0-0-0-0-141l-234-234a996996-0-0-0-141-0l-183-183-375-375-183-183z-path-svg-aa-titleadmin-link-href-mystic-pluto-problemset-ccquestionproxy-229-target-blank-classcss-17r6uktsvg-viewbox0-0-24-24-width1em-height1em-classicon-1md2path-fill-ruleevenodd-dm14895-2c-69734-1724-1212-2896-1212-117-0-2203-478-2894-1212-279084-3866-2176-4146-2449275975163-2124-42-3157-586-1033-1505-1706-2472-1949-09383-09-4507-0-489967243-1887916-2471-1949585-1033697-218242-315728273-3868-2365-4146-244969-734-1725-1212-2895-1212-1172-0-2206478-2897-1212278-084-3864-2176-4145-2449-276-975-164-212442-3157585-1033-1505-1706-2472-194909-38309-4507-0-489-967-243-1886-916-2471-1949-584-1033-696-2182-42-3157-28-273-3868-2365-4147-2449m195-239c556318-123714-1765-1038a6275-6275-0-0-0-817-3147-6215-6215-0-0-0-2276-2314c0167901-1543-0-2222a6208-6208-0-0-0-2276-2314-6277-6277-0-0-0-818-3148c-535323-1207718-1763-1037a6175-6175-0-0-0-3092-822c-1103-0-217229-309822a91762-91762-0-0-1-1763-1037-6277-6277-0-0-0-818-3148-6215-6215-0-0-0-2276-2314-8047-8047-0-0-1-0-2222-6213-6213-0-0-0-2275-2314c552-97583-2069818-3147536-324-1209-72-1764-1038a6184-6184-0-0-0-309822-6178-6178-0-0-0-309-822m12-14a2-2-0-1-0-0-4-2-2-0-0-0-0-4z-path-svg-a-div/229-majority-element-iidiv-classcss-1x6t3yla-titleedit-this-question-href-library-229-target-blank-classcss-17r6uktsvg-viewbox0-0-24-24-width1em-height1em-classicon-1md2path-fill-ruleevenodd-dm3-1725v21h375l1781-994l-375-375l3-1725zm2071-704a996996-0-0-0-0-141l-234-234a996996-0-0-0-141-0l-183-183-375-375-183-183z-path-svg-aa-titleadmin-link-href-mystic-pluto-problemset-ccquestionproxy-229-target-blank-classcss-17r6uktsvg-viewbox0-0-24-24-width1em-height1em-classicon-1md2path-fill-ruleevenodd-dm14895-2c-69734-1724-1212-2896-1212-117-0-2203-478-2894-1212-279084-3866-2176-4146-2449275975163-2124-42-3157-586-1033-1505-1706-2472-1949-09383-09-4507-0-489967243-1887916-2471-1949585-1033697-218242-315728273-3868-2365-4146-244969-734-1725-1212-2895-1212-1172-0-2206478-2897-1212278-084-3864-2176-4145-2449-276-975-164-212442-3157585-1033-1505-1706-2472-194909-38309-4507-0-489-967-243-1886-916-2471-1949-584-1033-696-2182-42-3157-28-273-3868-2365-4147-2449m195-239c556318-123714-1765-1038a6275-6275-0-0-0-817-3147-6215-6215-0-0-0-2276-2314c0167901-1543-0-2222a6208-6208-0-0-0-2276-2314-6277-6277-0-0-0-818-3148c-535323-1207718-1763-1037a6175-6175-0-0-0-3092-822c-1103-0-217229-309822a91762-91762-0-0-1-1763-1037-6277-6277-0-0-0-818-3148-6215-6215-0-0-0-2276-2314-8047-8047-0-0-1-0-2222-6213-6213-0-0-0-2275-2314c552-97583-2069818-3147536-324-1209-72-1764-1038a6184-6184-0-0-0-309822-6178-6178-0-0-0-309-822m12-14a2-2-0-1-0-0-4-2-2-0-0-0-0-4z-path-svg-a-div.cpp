class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int temp = INT_MIN , temp2 = INT_MIN , ct = 0 , ct2 = 0 , n = nums.size();
        for(int i = 0 ; i < n ;i++){
            if(nums[i] == temp)
            {
                temp = nums[i];
                ct++;
            }
            else if(nums[i] == temp2)
            {
                temp2 = nums[i];
                ct2++;
            }
            else if(ct == 0)
            {
                temp = nums[i];
                ct++;
            }
            else if(ct2 == 0)
            {
                temp2 = nums[i];
                ct2++;
            }
            else
                ct-- , ct2--;
        }
        ct = 0 , ct2 = 0;
        for(int i = 0;  i < n ;i++){
            if(nums[i] == temp)
                ct++;
            else if(nums[i] == temp2)
                ct2++;
        }
        vector<int> ans;
        if(ct > (n / 3))
            ans.push_back(temp);
        if(ct2 > (n / 3))
            ans.push_back(temp2);
        return ans;
    }
};