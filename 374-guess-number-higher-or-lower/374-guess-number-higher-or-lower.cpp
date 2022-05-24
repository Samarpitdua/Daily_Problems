/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long int low = 1 , high = n;
        while(low <= high)
        {
            int mid = (high + low) / 2;
            int let = guess(mid);
            if(!let)
                return mid;
            else if(let == -1)
                high = mid - 1;
            else
                low = mid + 1;
            
        }
        
        return -1;
    }
};