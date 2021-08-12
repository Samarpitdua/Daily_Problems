class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        vector<string>str(n);
        for(int i=0;i<strs.size();i++)
        {
            str[i]=strs[i];
        }
        map<string,vector<int>>mp;
        for(int i=0;i<strs.size();i++)
        {
            sort(strs[i].begin(),strs[i].end());
            mp[strs[i]].push_back(i);
        }
        vector<vector<string>>ans;
        vector<string>temp;
        for(auto x:mp)
        {
            for(auto y:x.second)
            {
                temp.push_back(str[y]);
            }
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
        
    }
};
