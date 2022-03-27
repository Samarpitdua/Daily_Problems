class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        vector<int> ans;
        vector<pair<int , int>> v(n);
        for(int i = 0 ; i < mat.size() ;i++)
        {
            int ct = 0;
            for(int j = 0 ; j < mat[0].size() ; j++)
            {
                if(mat[i][j])
                    ct++;
            }
            v[i] = {ct , i};
        }
        sort(v.begin() , v.end());
        for(auto x : v)
        {
            if(k-- > 0)
                ans.push_back(x.second);
            else 
                break;
        }
        return ans;
    }
};