class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>v;
        int n=matrix.size();
        int m=matrix[0].size();
        int hit=0,r=0,c=0;
        int up=0,left=0,right=m,down=n;
        while(v.size()!=n*m)
        {
            if(left>right or up>down)
                break;
            if(hit==0)
            {
                for(int i=left;i<right;i++)
                {
                    v.push_back(matrix[up][i]);
                }
                up++;
                hit=1;
            }
            else if(hit==1)
            {
                for(int i=up;i<down;i++)
                {
                    v.push_back(matrix[i][right-1]);
                }
                right--;
                hit=2;
            }
            else if(hit==2)
            {
                for(int i=right-1;i>=left;i--)
                {
                    v.push_back(matrix[down-1][i]);
                }
                down--;
                hit=3;
            }
            else if(hit==3)
            {
                for(int i=down-1;i>=up;i--)
                {
                    v.push_back(matrix[i][left]);
                }
                left++;
                hit=0;
            }
        }
        return v;
    }
};
