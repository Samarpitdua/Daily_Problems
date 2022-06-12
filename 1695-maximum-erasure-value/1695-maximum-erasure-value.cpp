class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        set<int> st;
        int n = nums.size();
        int ans = 0 , sum = 0;
        for(int i = 0 , j = 0 ;i < n ;i++)
        {
            while(st.find(nums[i]) != st.end())
            {
                st.erase(nums[j]);
                sum -= nums[j];
                j++;
            }
            st.insert(nums[i]);
            sum += nums[i];
            ans = max(ans , sum);
        }
        return ans;
    }
};