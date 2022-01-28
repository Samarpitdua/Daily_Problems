struct comp
{
    bool operator()(pair<int , int> a , pair<int , int> b)
    {
        if(a.first < b.first)
            return true;
        else if(a.first > b.first)
            return false;
        else
            return a.second > b.second;
    }
};
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int , int> mp;
        for(auto x : nums)
            mp[x]++;
        priority_queue<pair<int , int> , vector<pair<int , int>> , comp> pq;
        for(auto it = mp.rbegin() ; it != mp.rend() ;it++)
        {
            pq.push({it -> second , it -> first});
        }
        vector<int> ans;
        while(!pq.empty())
        {
            int temp = pq.top().first;
            int temp2 = pq.top().second;
            pq.pop();
            for(int i = 0 ; i < temp ;i++)
                ans.push_back(temp2);
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};