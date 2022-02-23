class Solution {
public:    
static bool comparator(string &s1 , string &s2)
    {
        if(s1.size() > s2.size())
            return true;
        else if(s1.size() < s2.size())
            return false;
        else
        {
            return s1 > s2;
        }
    }
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin() , nums.end() , comparator) ;
        return nums[ k - 1];
    }
};