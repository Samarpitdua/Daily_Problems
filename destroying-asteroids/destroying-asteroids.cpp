class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int ct = 0 , i = 0;
        long long mass2 = mass;
        sort(asteroids.begin() , asteroids.end());
        int n = asteroids.size();
        while(i < n)
        {
            if(mass2 >= asteroids[i])
                mass2 += asteroids[i] , ct++ , i++;
            else
                break;
        }
        
        return ct==n;
    }
};