class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        set<vector<int>>st;
        st.clear();
        sort(nums.begin(),nums.end());
        vector<vector<int>>v;
        int p=0;
        for(int i=0;i<n-2;i++)
        {
            
            int cal=-nums[i];
            for(int j=i+1,k=n-1;j<k;)
            {
                if(nums[j]+nums[k]>cal)
                    k--;
                else if(nums[j]+nums[k]<cal)
                    j++;
                else
                {
                    vector<int> triplet = {nums[i], nums[j], nums[k]};
                    if(st.find(triplet)==st.end())
                        v.push_back(triplet);
                    st.insert(triplet);
                    
                    //p++;
                    j++;
                    k--;
                }
            }
        }
        return v;
    }
};