class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // map<int , int>mp;
        // int n = nums.size();
        // for(int i = 0;i<nums.size();i++)
        //   mp[i]=nums[i];
        // for(int i = 0 ; i < nums.size() ; i++)
        // {
        //     nums[(i + k) % n] = mp[i];
        // }
        std :: rotate(nums.rbegin() , nums.rbegin() + k % nums.size() , nums.rend());
    }
};