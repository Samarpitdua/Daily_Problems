class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        for(int i = 0 ; i < n ;i++)
        {
            for(int j = n - 1 , k = 0 ; j >= k ;j-- , k++)
            {
                swap(image[i][j] , image[i][k]);
                image[i][j] ^= 1;           
                if(j != k)
                 image[i][k] ^= 1;
                
            }
        }
        return image;
    }
};