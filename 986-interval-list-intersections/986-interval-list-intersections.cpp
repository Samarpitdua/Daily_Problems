class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& fl, vector<vector<int>>& sl) {
        vector<vector<int>> ans;
        int f = fl.size() , s = sl.size();
        for(int i = 0 , j = 0 ; i < f and j < s ;){
            if(fl[i][1] < sl[j][0])
                i++;
            else if(sl[j][1] < fl[i][0])
                j++;
            else{
                int st = max(fl[i][0] , sl[j][0]);
                int en = min(fl[i][1] , sl[j][1]);
                ans.push_back({st , en});
                if(fl[i][1] < sl[j][1])
                    i++;
                else
                    j++;
            }
        }
        return ans;
        
    }
};