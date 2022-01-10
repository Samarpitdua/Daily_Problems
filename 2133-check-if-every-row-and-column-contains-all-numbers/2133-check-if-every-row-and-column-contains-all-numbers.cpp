class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        set<int> st;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                st.insert(matrix[i][j]);
            }
            if(st.size() != n)
                return false;
            st.clear();
        }
        st.clear();
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                st.insert(matrix[j][i]);
            }
            if(st.size() != n)
                return false;
            st.clear();
        }
        return true;
    }
};