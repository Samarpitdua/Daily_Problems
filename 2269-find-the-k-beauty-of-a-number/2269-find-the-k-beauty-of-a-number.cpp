#include<bits/stdc++.h>
class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string ans;
        int num2 = num;
        while(num2)
        {
            ans += to_string((num2 % 10));
            num2 /= 10;
        }
        reverse(ans.begin() , ans.end());
        int ct = 0;
        string temp = "";
        for(int i = 0 ; i < ans.size() ; i++)
        {
            if(i < (k - 1))
            {
                temp += ans[i];
            }
            else
            {
                temp += ans[i];
                int a = stoi(temp);
                if(a != 0 and num % a == 0)
                    ct++;
                temp.erase(temp.begin());
            }
        }
        return ct;
    }
};