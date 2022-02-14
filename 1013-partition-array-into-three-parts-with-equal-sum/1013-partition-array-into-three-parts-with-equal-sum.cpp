class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum2 = 0 , ct = 0 , temp = 0 , n = arr.size();
        int sum = accumulate(arr.begin() , arr.end() , sum2);
        if(sum % 3 != 0)
            return false;
        sum /= 3;
        for(int i = 0 ; i < n ; i++)
        {
            temp += arr[i];
          
            if(temp == sum)
            {
                temp = 0;
                ct++;
            }
        }
        if(ct >= 3)
            return true;
        return false;
        
    }
};