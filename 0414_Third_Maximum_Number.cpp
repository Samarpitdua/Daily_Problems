class Solution {
public:
    int thirdMax(vector<int>& nums) {
            int ct=0;
            map<int,int>mp;
            for(int i=0;i<nums.size();i++)
                mp[nums[i]]++;
            if(mp.size()<3)
            {
                return *max_element(nums.begin(),nums.end());
            }
            for(auto i=mp.rbegin();i!=mp.rend();i++)
            {
                ct++;
                if(ct==3)
                return i->first;
            }
        
        return -1;
    }
};
