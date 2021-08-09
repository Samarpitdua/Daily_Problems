//Approach 1, Complexity: nlogn
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
            nums[i]*=nums[i];
        sort(nums.begin(),nums.end());
        return nums;
        
    }
};
//Approach 2, Complexity : n
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int>v(n);
        n=n-1;
        for(int i=0,j=nums.size()-1;i<=j;)
        {
            if(abs(nums[i])>abs(nums[j]))
                v[n--]=nums[i]*nums[i],i++;
            else
                v[n--]=nums[j]*nums[j],j--;
        }
        return v;
    }
};
