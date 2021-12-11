class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        do
        {
            int p = stoll(s);
            if(p > n)
            {
                if( p > 0)
                return p;
            }
        }while(next_permutation(s.begin(),s.end()));
        return -1;
        
    }
};
