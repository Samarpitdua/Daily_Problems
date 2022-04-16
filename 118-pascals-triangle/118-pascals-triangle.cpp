class Solution {
public:
    //As we proceed at each row we get equal number of elements
    //If you want to find a value at a particualar row and column , the formula is-> r-1^C^c-1
    //---->O(n)complexity
    //Let's suppose you want to find any full row then observe the pattern
    //res*=(n-i),res/=(i+1);
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        vector<int> temp;
        for(int i = 1 ; i <= numRows ; i++)
        {
            temp.resize(i);
            if(i == 1)
            {
                temp[0] = 1;
                ans.push_back(temp);
                continue;
            }
            else
            {
                temp[0] = 1;
                temp[i - 1] = 1;
                for(int j = 1 ; j < (i - 1) ; j++)
                {
                    temp[j] = ans[i - 2][j - 1] + ans[i - 2][j];
                }
                ans.push_back(temp);
            }
        }
        return ans;
        
        
        
        
    // vector<vector<int>>ans(numRows);
    //     for(int i=0;i<numRows;i++)
    //     {
    //         ans[i].resize(i+1);
    //         ans[i][0]=ans[i][i]=1;//First and Last element will always be 1.
    //         for(int j=1;j<i;j++)
    //         {
    //             ans[i][j]=ans[i-1][j-1]+ans[i-1][j];
    //         }
    //     }
    //     return ans;
    }
};