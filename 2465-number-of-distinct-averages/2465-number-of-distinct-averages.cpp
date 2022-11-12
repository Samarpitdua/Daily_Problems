class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        set<double> st;
        sort(nums.begin() , nums.end());
        int n = nums.size();
        for(int i = 0 , j = n - 1; i < j;i++,j--)
        {
            double temp = (nums[i]+nums[j])/(double)2;
            st.insert(temp);
        }
        return st.size();
    }
};