class Solution {
public:
    void dfs(int i,int j,int newColor,vector<vector<int>>& image,vector<vector<int>>& vis,int required)
    {
        vis[i][j] = 1;
        if(i - 1 >= 0 and vis[i-1][j] == 0 and image[i - 1][j] == required)
        {
            image[i - 1][j] = newColor;
            dfs(i - 1 , j , newColor , image , vis , required);
        }
        if(i + 1 < image.size() and vis[i + 1][j] == 0 and image[i + 1][j] == required)
        {
            image[i + 1][j] = newColor;
            dfs(i + 1 , j , newColor , image , vis , required);
        }
        if(j - 1 >= 0 and vis[i][j - 1] == 0 and image[i][j - 1] == required)
        {
            image[i][j - 1] = newColor;
            dfs(i , j - 1 , newColor , image , vis , required);
        }
        if(j + 1<image[0].size() and vis[i][j + 1]==0 and image[i][j + 1] == required)
        {
            image[i][j + 1] = newColor;
            dfs(i , j + 1 , newColor , image , vis , required);
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int rows = image.size();
        int cols = image[0].size();
        int required = image[sr][sc];
        vector<vector<int>> vis(rows , vector<int> (cols,0));
        image[sr][sc] = newColor;
        dfs(sr , sc , newColor , image , vis , required);
        return image;
    }
};