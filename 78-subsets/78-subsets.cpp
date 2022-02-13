class Solution {
public:
    //2 choices lo ya na lo
    void calculate(vector<int> nums,int n,vector<vector<int>>& v,int i,vector<int>& k)
    {
        if(i==n)
        {
            v.push_back(k);
        }
        else
        {
            k.push_back(nums[i]);
            calculate(nums,n,v,i+1,k);
            k.pop_back();
            calculate(nums,n,v,i+1,k);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>v;
        vector<int>k;
        calculate(nums,nums.size(),v,0,k);
        return v;
        
        
    }
};