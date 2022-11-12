class Solution {
public:
    int minSwaps(vector<int>& data) {
        int n = data.size(), ct = 0;
        for(auto x : data){
            if(x)
                ct++;
        }
        
        if(ct == 1 or !ct) return 0;
        
        int ans = INT_MAX, swap = 0, init = 0;
        
        for(int i = 0, j = 0 ; i < n ;i++){
            if(data[i] == 1)
                init++;
            else
                swap++;
            if(init + swap == ct)
            {
                ans = min(ans , swap);
                if(data[j] == 1)
                    init--;
                else
                    swap--;
                j++;
            }
        }
        return ans;
    }
};