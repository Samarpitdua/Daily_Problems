 bool comp(vector<int> a , vector<int> b)
    {
        if(a[0] == b[0])
            return a[1] < b[1];
        else
            return a[0] > b[0];
    }
class Solution {
public:
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin() , people.end() , comp);
        
        vector<vector<int>> ans;
        for(auto x : people){
            ans.insert(ans.begin() + x[1] , x);
        }
        return ans;
    }
};