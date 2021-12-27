class Solution {
public:
    int check( string s , vector<int>& v , int n , int i)
    {
        int ct = 0;
        int x = v[0] ;
        int y = v[1] ;
        for( int j = i ; j < s.size() ; j++)
        {
            
            if( s[j] == 'D' )
                x++;
            else if( s[j] == 'U' )
                x--;
            else if( s[j] == 'L' )
                y--;
            else if( s[j] == 'R' )
                y++;
            if( x >= n or x < 0 or y >= n or y < 0)
                break;
            ct++ ;
        }
        return ct;
    }
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> ans ;
        int p = s.size();
        for(int i = 0 ; i< p ; i++)
        {
            int temp = check( s , startPos , n , i);
            ans.push_back(temp);
         //   cout<<i<<" ";
        }
        return ans;
    }
};