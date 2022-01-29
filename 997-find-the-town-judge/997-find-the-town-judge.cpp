class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        map<int , int> mp , mp2;
        set<int> st;
        if(trust.size() == 0 and n==1)
            return 1;
        for(int i = 0 ; i < trust.size() ; i++)
        {
            mp[trust[i][0]]++;
            mp2[trust[i][1]]++;
            st.insert(trust[i][1]);
        }
            int temp ;
            for(auto x : st)
            {
                temp = x;
                if(mp[temp] or mp2[temp] != (n-1))
                    continue;
                else
                    return temp;
            }
            return -1;
        
    }
};