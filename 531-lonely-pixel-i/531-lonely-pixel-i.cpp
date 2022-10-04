class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& pic) {
        int m = pic.size();
        int n = pic[0].size();
        int ct = 0;
        map<int , int> mp , mp2;
        for(int i = 0;  i < m ;i++){
            for(int j = 0;  j < n ;j++){
                if(pic[i][j] == 'B')
                {
                    mp[i]++;
                    mp2[j]++;
                }
            }
        }
        for(int i = 0;  i < m ;i++){
            for(int j = 0;  j < n ;j++){
                if(pic[i][j] == 'B' and mp[i] == 1 and mp2[j] == 1)
                {
                    ct++;
                }
            }
        }
        return ct;
        
    }
};