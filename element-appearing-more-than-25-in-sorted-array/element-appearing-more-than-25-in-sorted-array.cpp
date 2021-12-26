class Solution {
public:
    int findSpecialInteger(vector<int>& s) {
        int ct = 1;
        int  n = s.size() ; 
      //  sort(s.begin() , s.end());
        for(int i = 0 ; i < n - 1 ; i++ )
        {
            if(s[i] == s[i+1])
                ct++;
            else
                ct=1;
            if( (ct * 4) > n )
                return s[i];
        }
        return s[n-1];
        
    }
};