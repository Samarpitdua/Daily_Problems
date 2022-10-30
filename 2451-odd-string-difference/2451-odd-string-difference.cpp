class Solution {
public:
    string oddString(vector<string>& words) {
        int n = words[0].size();
        map<vector<int> , vector<string>> mp;
        
        for(int i = 0 ;i < words.size() ;i++)
        {
            vector<int> v;
            for(int j = 1 ; j < n ;j++)
            {
                v.push_back(words[i][j] - words[i][j - 1]);
            }
            mp[v].push_back(words[i]);
        }
        for(auto x : mp)
        {
            // cout<<mp[x.first].size()<<" ";
            if(mp[x.first].size() == 1)
            {
                return x.second[0];
            }
        }
        return "";
    }
};