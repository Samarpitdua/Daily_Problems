class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        vector<int> v;
        for(int i=0;i<seats.size();i++)
        {
            if(seats[i] == 1)
                v.push_back(i);
        }
        int n = seats.size();
        int m = v.size();
        vector< int >v2(m,0);
        int i = 0;
        for(auto x : v)
            v2[i++]=x;
        int maxdist = 0;
        for(int i = 0 ; i < m - 1; i++)
        {
            int dist = v2[i+1] - v2[i];
            maxdist=max(maxdist,dist);
        }
        if(v2.size() == 0)
            return n;
        int maxi =  max({maxdist/2,v2[0],n-v2[m-1]-1});
        return maxi;
        
    }
};