class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        map<int , int> mp;
        int rep,miss;
        for(int i = 0 ; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        for(int i = 1 ; i <= nums.size() ;i++)
        {
            if(mp.find(i) == mp.end())
            {
                miss = i;
            }
            else if(mp[i] == 2)
                rep = i;
                
                
        }
        ans.push_back(rep);
        ans.push_back(miss);
        
        return ans;
    }
};