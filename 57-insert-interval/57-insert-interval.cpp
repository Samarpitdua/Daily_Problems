class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& n) {
        vector<vector<int>> ans;
        int n1 = in.size();
        int p= -1;
        for(int i = 0 ; i < in.size() ;i++){
            if(in[i][1] < n[0])
            {
                // cout<<"vv ";
                ans.push_back(in[i]);
                continue;
            }
            else{
                // in[i][1] = n[1];
                p = i;
                break;
            }
        }
        if(p == -1){
            ans.push_back(n);
            return ans;
        }
        int i = p;
        vector<int> temp(2);
            while(i < n1 and in[i][0] <= n[1])
            {
                // cout<<"hl";
                i++;
            }
            if(i == n1){
                temp[0] = min(n[0] , in[p][0]);
                temp[1] = max(in[n1-1][1] , n[1]);
                ans.push_back(temp);
                return ans;
            }
            else{
                temp[0] = min(n[0] , in[p][0]);
                if(i-1>=0)
                temp[1] = (max(in[i - 1][1] , n[1]));
                else
                    temp[1] = n[1];
                ans.push_back(temp);
            }
            while(i < n1){
                ans.push_back(in[i]);
                i++;
            }
                
            return ans;

        
    }
};