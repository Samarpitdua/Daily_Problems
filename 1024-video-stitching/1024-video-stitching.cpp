class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        int start = 0;
        int end = time;
        int ans = 0 , maxi = 0;
        while(maxi < end)
        {
            int p = 0;
            for(int i = 0 ; i < clips.size() ;i++)
            {
                int l = clips[i][0];
                int r = clips[i][1];
                if(l <= start and r > maxi)
                {
                    p = 1;
                    maxi = r;
                }
            }
            if(p == 0)
                return -1;
            start = maxi;
            ans++;
        }
        return ans;
    }
};