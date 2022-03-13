class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        set<int> st;
        for(int i = 0 ; i < nums.size() ;i++)
        {
            if(nums[i] != key)
                continue;
            int l = k , m = k ;
            for(int j = i ; j >= 0 and l >= 0 ; j-- , l--)
            {
                st.insert(j);
            }
            for(int j = i ; j < nums.size() and m >= 0 ; m-- , j++)
                st.insert(j);
            
        }
        for(auto x : st)
            ans.push_back(x);
        return ans;
    }
};