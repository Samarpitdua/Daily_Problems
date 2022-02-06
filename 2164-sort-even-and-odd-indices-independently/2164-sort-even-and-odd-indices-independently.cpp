class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> v1 ; 
        vector<int> v2 ; 
        int n = nums.size();
        for(int i = 0 ; i < n ;i++)
        {
            if(i & 1)
                v1.push_back(nums[i]);
            else
                v2.push_back(nums[i]);
        }
        sort(v1.begin() , v1.end() , greater<int>());
        sort(v2.begin() , v2.end());
        vector<int> ans1(v1.size());
        vector<int> ans2(v2.size());
        int i = 0;
        for(auto x : v1)
            ans1[i++] = x;
        i = 0;
        for(auto x : v2)
            ans2[i++] = x;
        
        vector<int> ans(n);
        int j=0,k=0,p=0;
        for(int i = 0 ; i < n ;i++)
        {
            if(p)
                p = 0 , ans[i] = ans1[j++];
            else
                p = 1 , ans[i] = ans2[k++];
        }
            return ans;
    }
};