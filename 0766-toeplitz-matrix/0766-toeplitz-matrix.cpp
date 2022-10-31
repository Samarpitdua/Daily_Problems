class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
     // #Let's tackle this . Draw shadow matrix and observe
        map<int , int> mp;
        for(int i = 0 ; i < matrix.size() ;i++)
        {
            for(int j = 0 ; j < matrix[0].size() ;j++)
            {
                int temp = (i - j);
                if(mp.find(temp) != mp.end())
                {
                    if(mp[temp] != matrix[i][j])
                        return false;
                }
                else
                {
                    mp[temp] = matrix[i][j];
                }
            }
        }
        return true;
    }
};