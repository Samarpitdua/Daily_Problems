class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        set<int> st;
        for(auto x : nums)
        {
            if(x)
                st.insert(x);
        }
        return st.size();
    }
};