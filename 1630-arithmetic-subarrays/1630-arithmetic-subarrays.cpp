class Solution {
public:
    bool solve(vector<int>& nums , int y , int z)
    {
        vector<int> temp;
        for(int i = y ; i <= z ;i++)
        {
            temp.push_back(nums[i]);
        }
        sort(temp.begin() , temp.end());
        if(temp.size() < 2)
            return false;
        
        int diff = temp[1] - temp[0];
        // for(auto x : temp)
        //     cout<<x<<" ";
        // cout<<diff<<endl;
        for(int i = 1 ; i < temp.size() - 1 ; i++){
            if(diff == (temp[i + 1] - temp[i]))
            {
                continue;
            }
            else
            {
                // cout<<(nums[i + 1] - nums[i])<<endl;
                return false;
            }
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        int m = l.size() , n = nums.size() , j = 0;
        while(j < m)
        {
            int y = l[j];
            int z = r[j];
            j++;
            ans.push_back(solve(nums , y ,z));
        }
        return ans;
    }
};