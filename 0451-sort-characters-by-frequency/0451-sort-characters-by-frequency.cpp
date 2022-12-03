class Solution {
public:
    string frequencySort(string s) {
        map<char , long long int > mp;
        for(int i = 0 ; i< s.size() ;i++)
            mp[s[i]]++;
        vector<pair< char , long long >> v;
        priority_queue<pair<int,int>>pq;
        for(auto x : mp)
        {
            pq.push({x.second , x.first});
        }
        sort(v.begin() , v.end());
        reverse(v.begin() , v.end());
        string ans = "";
        while(!pq.empty())
        {
            int p = pq.top().first;
            char q = pq.top().second;
            while(p--)
            {
                ans += q;
            }
            pq.pop();
        }
        return ans;
        
    }
};