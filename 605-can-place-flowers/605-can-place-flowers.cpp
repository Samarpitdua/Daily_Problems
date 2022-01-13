class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();
        if(m == 1 and flowerbed[0] == 0)
            n--;
        else{
        for(int  i = 0 ; i < m ; i++)
        {
            if(n == 0)
                break;
            if(i == 0)
            {
                if(flowerbed[i] == 0 and flowerbed[i + 1] == 0)
                    flowerbed[i] = 1 , n--;
            }
            else if(i == m  - 1)
            {
                if(flowerbed[i] == 0 and flowerbed[i - 1] == 0)
                    flowerbed[i] = 1 , n--;
            }
            else
            {
                if(flowerbed[i] == 0 and flowerbed[i - 1] == 0 and flowerbed[i + 1] == 0)
                    flowerbed[i] = 1 , n--;
            }
                
        }
        }
        return (n <= 0);
    }
};