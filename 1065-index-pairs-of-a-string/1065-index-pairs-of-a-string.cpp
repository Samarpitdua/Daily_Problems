class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        vector<vector<int>> res;
        for(auto w : words)
        {
            int p = text.find(w);
            while (p != string::npos)
            {
                res.push_back({p, p + (int)w.size() - 1});
                p = text.find(w, p + 1);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};