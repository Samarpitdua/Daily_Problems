struct comp
{
bool operator()(pair< int , string>& a, pair<int , string>& b)
    {
            return a.first > b.first || (a.first == b.first && a.second < b.second);
    }
};
class Solution {
public:
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map< string , int > mp;
        for(auto x : words)
            mp[x]++;
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, comp> pq;
        for(auto x : mp)
        {
            pq.push({x.second , x.first});
            if(pq.size() > k)
                pq.pop();
        }
        vector<string> ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};