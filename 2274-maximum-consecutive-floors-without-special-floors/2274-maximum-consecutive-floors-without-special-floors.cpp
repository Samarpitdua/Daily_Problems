class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int ct = 0 , ans = 0;
        sort(special.begin() , special.end());
        int sz = special.size();
        int j = 0;
        
        for(int i = bottom ; i <= top ;)
        {
            if(j < sz and i == special[j])
            {
                ct = 0;
                i = special[j] + 1;
                j++;
            }
            else if(j == sz)
            {
                ct = top - i + 1;
                i = top + 1;
            }
            else
            {
                ct = special[j] - i ;
                i = special[j] + 1; 
                j++;
            }
            ans = max(ans , ct);
        }
        return ans;
    }
};