class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> temp;
        for(int i = 1 ;i <= numRows ; i++){
            temp.resize(i);
            temp[0] = 1;
            temp[i - 1] = 1;
            for(int j = 1 ;j < i - 1 ;j++){
                temp[j] = ans[i - 2][j - 1] + ans[i - 2][j];
            }
            ans.push_back(temp);
        }
        return ans;
    }
};