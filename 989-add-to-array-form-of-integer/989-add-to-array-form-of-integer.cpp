class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int temp = 0 , carry = 0 , n = num.size();
        int i = 0;
        for(i = n - 1 ; i >= 0 ;)
        {
            temp = 0;
            if(k == 0 and carry == 0)
                break;
            if(k > 0)
            {
                temp = k % 10;
                k /= 10;
            }
            temp = temp + num[i] + carry;
            cout << temp << " ";
            if(temp > 9)
            {
                carry = temp / 10;
                num[i] = temp % 10;
                i--;
                while(carry)
                {
                    if( i < 0)
                        break;
                    temp = 0;
                    temp = carry + num[i] + k % 10;
                    k /= 10;
                    carry = temp / 10;
                    num[i] = temp % 10;
                    i--;
                }
            }
            else
            {
                num[i] = temp % 10;
                i--;
            }
            
            if(i < 0)
                break;
        }
        vector<int> ans2;
        if(i == -1)
        {
            while(1){
            if(k==0)
                break;
            temp = carry + k % 10;
            k /= 10;
            carry = temp / 10;
            ans2.push_back(temp % 10);
            }
        }
        if(carry)
            ans2.push_back(carry);
        
        
        
        
        reverse(ans2.begin() , ans2.end());
        vector<int> ans;
        for(auto x : ans2)
            ans.push_back(x);
        for(auto x : num)
            ans.push_back(x);
        return ans;
    }
};