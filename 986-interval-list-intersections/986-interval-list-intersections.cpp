class Solution {
public:
vector<vector<int>> intervalIntersection(vector<vector<int>>& v, vector<vector<int>>& v2) {
    vector<vector<int>> ans;
    int n = v.size() , m = v2.size();
    for(int i = 0 , j = 0 ; i < n and j < m ;)
    {
        //cout<<i<<" "<<j<<endl;
        int x = v[i][0] , y = v[i][1];
        int p = v2[j][0] , q = v2[j][1];
        vector<int> temp;
        
         if(p < x and q < x)
        {
            j++;
            continue;
        }
         if(p > x and p > y)
        {
            i++;
            continue;
        }
        if(x <= p and y >= q)
        {
            temp.push_back(p);
            temp.push_back(q);
            j++;
        }
        else if(p <= x and q >= y)
        {
            temp.push_back(x);
            temp.push_back(y);
            i++;
        }
        else if(x <= p and y <= q)
        {
            temp.push_back(p);
            temp.push_back(y);
            i++;
        }
        else if(x >= p and y >= q)
        {
            temp.push_back(x);
            temp.push_back(q);
            j++;
        }
        //else if()
        ans.push_back(temp);
    }
        return ans;
}
};