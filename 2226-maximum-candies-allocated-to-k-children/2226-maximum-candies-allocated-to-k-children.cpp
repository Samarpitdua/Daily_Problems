class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long int sum = 0 , ans = 0;
        int n = candies.size();
        for(auto x : candies)
            sum += x;
        if(sum < k)
            return 0;
            int left = 1 , right = 1e7;
            while(left < right)
            {
                long long int mid = (right + left + 1) / 2;
                long long int y = 0;
                for(int i = 0 ; i < n ;i++)
                {
                    y += (candies[i] / mid);
                }
                if(y < k)
                {
                    right = mid - 1;
                }
                else
                    left = mid;
            }
            return left;
    }
};