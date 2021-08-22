class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ct=0,sum=0;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]<0)
                    ct++;
                sum+=abs(matrix[i][j]);
            }
        }
        if(ct%2==0)
            return sum;
        else
        {
            long long mini=INT_MAX;
            for(int i=0;i<matrix.size();i++)
            {
                for(int j=0;j<matrix[0].size();j++)
                {
                    if(abs(matrix[i][j])<mini)
                        mini=abs(matrix[i][j]);
                }
            }
            long long ans=(sum-abs(mini)*2);
            return ans;
        }
        
    }
};
