class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int>v;
        int n=changed.size();
        if(n&1)
            return v;
        sort(changed.begin(),changed.end());
        map<int,int>mp;
        for(auto x:changed)
            mp[x]++;
        for(int i=0;i<n;i++)
        {
            if(v.size()==n/2)break;
            if(changed[i]==0 and mp[0]>0)
            {
                if(mp[0]>1)
                {
                    mp[0]-=2;
                    v.push_back(0);
                }
                else
                {
                    vector<int>v2;
                    return v2;
                }
            }
            else if(mp[changed[i]*2]>0 and mp[changed[i]]>0)
            {
                mp[changed[i]*2]--;
                mp[changed[i]]--;
                v.push_back(changed[i]);
            }
            else
            {
                continue;
            }
        }
        if(v.size()<n/2)
        {
            vector<int>v2;
            return v2;
        }
        
    return v;
        
    }
};