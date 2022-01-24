class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();
        string ans(n + m , '0');
        int carry = 0;
        for(int i = n - 1 ; i >= 0 ;i--)
        {
            carry = 0;
            for(int j = m - 1 ; j >= 0 ;j--)
            {
int temp = (ans[i + j + 1] - '0') +(num1[i] - '0') * (num2[j] - '0') + carry;
                ans[i + j + 1] = (temp % 10) + '0';
                carry = temp / 10;
            }
            ans[i] += carry ;   
        }
        int i = 0;
        if(ans.size() == 1)
            return ans;
        while(i < ans.size() and ans[i] == '0')
        {
            i++;
            continue;
        }
        string prop = "";
        
        while(i < ans.size())
        {
            prop += ans[i++];
        }
        if(prop.size() == 0)
            return "0";
        return prop;
            
        
    }
};