class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
        int n = nums.size();
        if(n == 1)
        {
            vector<int>v;
            v.push_back(-1);
            return v;
        }
        
        vector<int>v;
        for(int i = n - 2;i >= 0;i--)
            st.push(nums[i]);
        for(int i = n - 1;i >= 0;)
        {
            if(st.empty())
            {
                v.push_back(-1);
                st.push(nums[i]);
                i--;
                continue; 
            }
            if(st.top()>nums[i])
            {
                
                v.push_back(st.top());
                st.push(nums[i]);
                i--;
            }
            else
            {
                st.pop();
            }
        }
        reverse(v.begin(),v.end());
        return v;
    }
};
