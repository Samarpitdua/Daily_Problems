class Solution {
public:
    int arraySign(vector<int>& nums) {
        int pos=0,zero=0,neg=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
                pos++;
            else if(nums[i]<0)
                neg++;
            else
                zero++;
        }
        if(zero)
            return 0;
        else if(neg%2==0)
            return 1;
        else
            return -1;
        
        
    }
};
