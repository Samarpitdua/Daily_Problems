class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = 1 , mini = 1;
        int ans = *max_element(nums.begin() , nums.end());
        for(auto x : nums){
            if(x == 0)
                maxi = 1 , mini = 1;
            else{
                int tmp = maxi;
                maxi = max({x * maxi , x * mini , x});
                mini = min({x * mini , x * tmp , x});
                ans = max(maxi , ans);
            }
        }
        return ans;
    }
};