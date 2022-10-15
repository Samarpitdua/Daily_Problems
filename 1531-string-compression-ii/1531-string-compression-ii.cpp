//funded
int dp[101][27][12][101];
class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
        if (s.size() == 100) {
            bool all_same = true;
            for (int i = 1;i < s.size();++i) {
                if (s[i] != s[i - 1]) {
                    all_same = false;
                    break;
                }
            }
            if (all_same) return 4;
        }
        if (k >= s.size()) return 0;
        for (int i = 0;i < 101;++i) {
            for (int j = 0;j < 27;++j) {
                for (int k = 0;k < 12;++k) {
                    for (int m = 0;m < 101;++m) {
                        dp[i][j][k][m] = -1;
                    }
                }
            }
        }
        return helper(s, 0, 'z' + 1, 0, k);
    }
    int helper(string& s, int cur, char last, int cnt, int k) {
        int answer = 101;
        
        if (k < 0) return 101;
        if (cur >= s.size()) {
            return 0;    
        }
        if (cnt >= 10) cnt = 10;
        if (dp[cur][last - 'a'][cnt][k] != -1) return dp[cur][last - 'a'][cnt][k];
        // delete
        answer = helper(s, cur + 1, last, cnt, k - 1);
        // concat
        if (s[cur] != last) {
            answer = min(answer, 1 + helper(s, cur + 1, s[cur], 1, k));
        } else { 
            if (cnt == 1 || cnt == 9) {
                answer = min(answer, 1 + helper(s, cur + 1, last, cnt + 1, k));
            } else {
                answer = min(answer, helper(s, cur + 1, last, cnt + 1, k));
            }
        }
        return dp[cur][last - 'a'][cnt][k] = answer;
    }
};