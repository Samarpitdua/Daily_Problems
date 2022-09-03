class Solution {
public:
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        queue<int> q;
        q.push(1);
        q.push(2);
        q.push(3);
        q.push(4);
        q.push(5);
        q.push(6);
        q.push(7);
        q.push(8);
        q.push(9);
        int ct = 1;
        while(!q.empty()){
            if(ct == n)
                break;
            int sz = q.size();
            while(sz--){
                int n = q.front() % 10;
                int temp = q.front();
                q.pop();
                for(int j = 0 ; j <= 9 ;j++)
                {
                    if(abs(n - j) == k)
                    {
                        q.push(temp * 10 + j);
                    }
                }
            }
            ct++;
        }
        while(!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};