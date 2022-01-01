bool compare(string a,string b)
    {
        return a+b>b+a;
    }
class Solution {
public:
    
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans(n);
        for(int i = 0; i < n ;i++)
        {
            ans[i] = to_string(nums[i]);
        }
        sort(ans.begin(),ans.end(),compare);
        string temp = "";
        for(auto x : ans)
            temp += x;
        string ans2 = "";
        int m = temp.size();
        while(temp.size()>1)
        {
            if(temp[0] == '0')
                temp.erase(0,1);
            else 
                break;
        }
        return temp;
    }
};