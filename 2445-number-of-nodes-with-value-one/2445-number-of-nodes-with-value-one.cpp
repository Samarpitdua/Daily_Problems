class Solution {
public:
    int numberOfNodes(int n, vector<int>& queries) {
        vector<int> tree(n + 1 , 0);
        
        for(int q : queries) {
            tree[q]++;
        }
        
        int cnt = (tree[1] % 2);
        for(int i = 2; i < tree.size(); ++i) {
            tree[i] += tree[i/2];
            cnt += (tree[i] % 2);
        }

        return cnt;
    }
};