class Solution {
public:
    vector<int> partitionLabels(string s) {
        int ct = 0;
        vector<int> ans;
        unordered_map<char , int> mp;
        int n = s.size();
        for(int i = 0 ; i < n ; i++)
        {
            mp[s[i]] = i;
        }
        for(int i = 0 ; i < n ; i++)
        {
            int temp = mp[s[i]];
            while(i < temp)
            {
                i++;
                temp = max(temp , mp[s[i]]);
            }
            ct = i - ct + 1;
            ans.push_back(ct);
            ct = i + 1;
        }
        return ans;        
    }
};