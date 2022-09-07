int trie[250005][26];

class Solution {
public:
    int countDistinct(string s) {
        int cnt = 0, n = s.length();
        memset(trie, 0, (n*n*26*4));
        for(int i = 0; i < n; i++) {
            int cur = 0;
            for(int j = i; j < n; j++) {
                int &nxt = trie[cur][s[j]-'a'];
                if(!nxt) nxt = ++cnt;
                cur = nxt;
            }
        }
        return cnt;
    }
};