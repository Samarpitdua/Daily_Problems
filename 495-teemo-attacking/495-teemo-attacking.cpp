class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if(duration == 0)
            return 0;
        int n = timeSeries.size() , ct = 0;
        for(int i = 0 ; i < n; i++)
        {
            if(i == n-1)
            {
                ct += duration;
                break;
            }
            if((timeSeries[i] + duration - 1) >= timeSeries[i+1])
            {
                ct += (timeSeries[i+1] - timeSeries[i] );
            }
            else
            {
                ct += duration;
            }
        }
        return ct;
        
    }
};