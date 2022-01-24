class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int n = name.size() , m = typed.size() , j = 0;
        for(int i = 0 ;i < n ;)
        {
            int ct2 = 0 ,ct = 0; 
            char temp = name[i];
            while(i < n  and name[i] == temp)
            {
                ct++;
                i++;
            }
            while(j < m and typed[j] == temp)
            {
                ct2++;
                j++;
            }
         //   cout<<ct2<<" "<<ct<<"\n";
            if(ct2 < ct)
                return false;
            if(i == n and j == m)
                break;
            if(i == n and j < m)
                return false;
        }
        return true;
    }
};