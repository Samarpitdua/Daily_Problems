// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


 // } Driver Code Ends

class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    bool isValid(int grid[9][9] , int ch , int row , int col)
    {
        for(int i = 0 ; i < 9 ;i++)
        {
            if(grid[row][i] == ch)return false;
            if(grid[i][col] == ch)return false;
            if(grid[3*(row / 3) + i / 3][3*(col / 3) + i % 3]== ch)return false;
        }
        return true;
    }
    bool SolveSudoku(int grid[N][N])  
    { 
        for(int i = 0 ;i < 9 ; i++)
        {
            for(int j = 0 ; j < 9 ; j++)
            {
                if(grid[i][j] == 0)
                {
                    for(int ch = 1 ; ch <= 9 ;ch++)
                    {
                        if(isValid(grid , ch , i , j))
                        {
                            grid[i][j] = ch;
                            if(SolveSudoku(grid))
                                return true;
                            grid[i][j] = 0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
        // Your code here
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for(int i = 0 ; i < 9 ; i++)
        {
            for(int j = 0 ; j < 9 ;j++)
                cout<<grid[i][j]<<" ";
            //cout<<"\n";
        }
        // Your code here 
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}  // } Driver Code Ends