class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low = 0;
        int ans = -1;
        int n = letters.size();
        int high = n - 1;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(letters[mid] <= target)
                low = mid + 1;
            else
            {
                ans = mid;
                high = mid - 1;
            }
        }
        if(ans == -1)
            ans = 0;
        return letters[ans];
    }
};