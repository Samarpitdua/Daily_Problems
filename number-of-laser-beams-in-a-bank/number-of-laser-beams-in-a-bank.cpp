class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ct = 0 , temp = -1 , ans = 0;
        for( int i = 0 ;i < bank.size() ; i++)
        {
            for(int j = 0 ; j < bank[i].size() ; j++)
            {
                if(bank[i][j] == '1')
                    ct++;
            }
            cout<<ct<<" ";
            if(ct){
            if(temp == -1)
                temp = ct , ct = 0;
            else
            {
                ans += temp * ct;
                temp = ct , ct = 0;
            }
            }
        }
        return ans;
    }
};