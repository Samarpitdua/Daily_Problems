class Solution {
public:
    int largestInteger(int num) {
        vector<int> odd , even , ans;
        
        while(num)
        {
            int temp = num % 10;
            num /= 10;
            if(temp % 2)
                odd.push_back(temp);
            else
                even.push_back(temp);
            ans.push_back(temp);
        }
        sort(odd.begin() , odd.end());
        sort(even.begin() , even.end());
        int j = 0 , k = 0;
        for(int i = 0 ; i < ans.size() ; i++)
        {
            if(ans[i] % 2 == 0)
                ans[i] = even[j++];
            else
                ans[i] = odd[k++];
        }
        reverse(ans.begin() , ans.end());
        int l = 0;
        for(auto x : ans)
        {
            l = l * 10 + x;
        }
        return l;
    }
};