class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int farthest = 0;
        int curr = 0 , jumps = 0;
        for(int i = 0 ; i < n - 1;i++)
        {
            farthest = max(farthest , i + nums[i]);    
            if(i == curr)
            {
                curr = farthest;
                jumps++;
            }
        }
        return jumps;
    }
};