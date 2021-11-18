class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>v;
        set<int>st;
        for(auto x:nums)
            st.insert(x);
        for(int i=1;i<=nums.size();i++)
        {
            if(st.find(i)==st.end())v.push_back(i);
        }
        return v;
        
        
    }
};
