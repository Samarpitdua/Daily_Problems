class Solution {
public:
    string greatestLetter(string s) {
        int sm[26]={0} , up[26]={0};
        for(auto x : s)
        {
            if(x >= 'a' and x <= 'z')
            sm[x - 'a']++;
            else
                up[x-'A']++;
            
        }
        // int a[26] = {A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z};\]
        string x = "";
        for(int i=25;i>=0;i--)
        {
            if(sm[i] and up[i])
            {
                x += 'A' + i;
                return x;
            }
        }
        return "";
        
    }
};