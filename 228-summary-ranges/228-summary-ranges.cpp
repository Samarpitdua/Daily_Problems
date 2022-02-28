class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int start = -1 , end = 0;
        int n = nums.size();
        for(int i = 0 ; i < nums.size();i++)
        {
            if(i < (n - 1) and (nums[i] + 1) == nums[i + 1] )
            {
                if(start != -1)
                    continue;
                else
                    start = i;
            }
            else
            {
                end = i;
                string ans2 = "";
                if(start == -1)
                    start = end;
                if(start == end)
                {
                    ans2 += (to_string(nums[start]));
                }
                else
                {
                    ans2 += (to_string(nums[start]));
                    ans2 += ("->");
                    ans2 += (to_string(nums[end]));
                }
                ans.push_back(ans2);
                start = -1 , end = -1;
            }
        }
        return ans;
    }
};