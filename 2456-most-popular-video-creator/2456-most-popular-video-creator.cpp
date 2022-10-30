class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        int n = ids.size();
        vector<vector<string>> v;
        map<string , long long int> mp;
        long long int maxi = 0;
        for(int i = 0 ; i < n ;i++)
        {
            if(mp.find(creators[i]) != mp.end())
                mp[creators[i]] += views[i];
            else
                mp[creators[i]] = views[i];
            maxi = max(maxi , mp[creators[i]]);
        }
        map<string , pair<long long int , string>> mp2;
        for(int i = 0 ; i < n ;i++)
        {
            if(mp[creators[i]] == maxi)
            {
                if(mp2.find(creators[i]) != mp2.end())
                {
                    if(mp2[creators[i]].first > views[i])
                        continue;
                    else if(mp2[creators[i]].first < views[i])
                    {
                        mp2[creators[i]].first = views[i];
                        mp2[creators[i]].second = ids[i];
                    }
                    else
                    {
                        mp2[creators[i]].second = min(ids[i] , mp2[creators[i]].second);
                        // cout<<ids[i]<<" "<<mp2[creators[i]].second<<endl;
                    }
                }
                    
                else
                    mp2[creators[i]].first = views[i] , mp2[creators[i]].second = ids[i];
            }
        }
        for(auto x : mp2)
        {
            vector<string> temp;
            temp.push_back(x.first);
            temp.push_back(x.second.second);
            v.push_back(temp);
        }
        return v;
    }
};