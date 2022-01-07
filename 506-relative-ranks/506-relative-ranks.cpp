class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> ans ;
        unordered_map<int,int> mp;
        vector<int> temp = score;
        sort(temp.begin() , temp.end() , greater<int>()) ;
        int ct = 1;
        
        //Storing positions in sorted order
        for(int i = 0 ;i < temp.size() ; i++)
            mp[temp[i]] = ct++;
        
        //Assigning Values
        for(int i = 0 ; i < n ; i++)
        {
            if(mp[score[i]] > 3)
            {
                ans.push_back(to_string(mp[score[i]]));
            }
            else if(mp[score[i]] == 1)
                ans.push_back("Gold Medal");
            else if(mp[score[i]] == 2)
                ans.push_back("Silver Medal");
            else if(mp[score[i]] == 3)
                ans.push_back("Bronze Medal");
            
        }
        return ans;
        
    }
};