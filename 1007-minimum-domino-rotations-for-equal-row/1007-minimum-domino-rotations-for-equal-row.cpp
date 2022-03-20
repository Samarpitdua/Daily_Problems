class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ct = 1;
        int ans = INT_MAX;
        for(int ct = 1 ; ct <= 6 ; ct++){
            int p = 0 , temp = 0;
        for(int i = 0 ; i <tops.size() ;i++)
        {
            if(tops[i] == ct)
                continue;
            else if(bottoms[i] == ct)
                temp++;
            else
            {
                p = 1;
                break;
            }
        }
            if(p == 1)
                continue;
            else
                ans = min(ans , temp);
                
        }
        for(int ct = 1 ; ct <= 6 ; ct++){
            int p = 0 , temp = 0;
        for(int i = 0 ; i <bottoms.size() ;i++)
        {
            if(bottoms[i] == ct)
                continue;
            else if(tops[i] == ct)
                temp++;
            else
            {
                p = 1;
                break;
            }
        }
            if(p == 1)
                continue;
            else
                ans = min(ans , temp);
                
        }
        if(ans == INT_MAX)
            return -1;
        else
            return ans;
    }
};