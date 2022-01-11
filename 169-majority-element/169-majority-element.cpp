class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ct = 1 , temp = nums[0];
        int n = nums.size();
        for(int i = 1 ; i < n ; i++ )
        {
            if(temp == nums[i])
                ct++;
            else
            {
                if(ct == 0)
                {
                    ct = 1;
                    temp = nums[i];
                }
                else
                    ct--;
            }
        }
        
        return temp;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        // int ct=1;
        // int temp=nums[0];
        // for(int i=1;i<nums.size();i++)
        // {
        //     if(nums[i]==temp)
        //         ct++;
        //     else
        //         ct--;
        //     if(ct==0)
        //         ct=1,temp=nums[i];
        //     //cout<<temp<<" "<<ct<<"\n";
        // }
        // return temp;
    }
    
};