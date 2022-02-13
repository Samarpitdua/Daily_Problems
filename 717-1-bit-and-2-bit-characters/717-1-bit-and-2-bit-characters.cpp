class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        if(n == 1)
        {
            return true ;
        }
        for(int i = 0 ; i < n - 1 ;i++)
        {
            if(bits[i] == 0)
                continue;
            else if(bits[i] == 1)
            {
                if(i == 0)
                {
                    bits[i + 1] = 2;
                    bits[i] = 2;
                }
                else
                {
                    bits[i + 1] = 2;
                }
                
            }
        }
        // for(auto x:bits)
        //     cout<<x<<" ";
        if(bits[n - 1] == 0 and bits[n - 2] ==0)
            return true;
        else if(bits[n - 1] == 2)
            return false;
        else if(bits[n - 2] == 2)
        {
            return true;
        }
        else
            return false;
    }
};
