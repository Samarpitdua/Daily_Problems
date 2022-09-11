class Solution {
public:
    static bool comp(vector<int>& w1, vector<int>& w2) {
        return w1[1] > w2[1];
    }
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<vector<int>> ans;
        vector<int> tmp(2 , 0);
        for (int i = 0; i < n; i++) {
            tmp[0] = speed[i];
            tmp[1] = efficiency[i];
            ans.push_back(tmp);
        }
        sort(ans.begin(), ans.end(), comp);
        long res = 0;
        long total = 0;
        long mine;
        for (int i = 0; i < k; i++) {
            total += ans[i][0];
            mine = ans[i][1];
            res = max(res, total * mine);
            pq.push(ans[i][0]);
        }
        for (int i = k; i < n; i++) {
            if (ans[i][0] > pq.top()) {
                total += (-pq.top() + ans[i][0]);
                mine = ans[i][1];
                res = max(res, total*mine);
                pq.pop();
                pq.push(ans[i][0]);
            }
        }
        return (int)(res%1000000007);   
    }
};