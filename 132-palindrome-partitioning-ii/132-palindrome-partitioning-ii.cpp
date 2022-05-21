// class Solution {
// public:
//     bool isPallin(string s , int i , int j)
//     {
//         while(i < j)
//         {
//             if(s[i] != s[j])return false;
//             i++ , j--;
//         }
//         return true;
//     }
//     int minCut(string s) {
//         int n = s.size();
//         vector<int> dp(n + 1 , 0);
//         for(int i = n - 1 ; i >= 0 ;i--)
//         {
//             int ans= INT_MAX;
//             for(int j = i ; j < n ;j++)
//              {
//                 int a = 0;
//                     a = isPallin(s , i , j);
//                 if(a)
//                 {
//                      ans = min(ans , 1 + dp[j + 1]);
//                 }
//             }
//             dp[i] = ans;
//         }
//         return dp[0] - 1;
//     }
// };
class Solution {
public:

bool isPalindrome(string &s, int start, int end){
    while(start < end){
        if(s[start] != s[end]) return false;
        start++, end--;
    }
    return true;
}

int f(int i, string &s, vector<int> &dp){
    
    if(i >= s.length()) return 0;
    if(dp[i] != -1) return dp[i];
    
    int mini = INT_MAX;
    for(int j=i;j<s.length();j++){
        if(isPalindrome(s, i, j)) mini = min(mini, 1 + f(j+1, s, dp));
    }
    return dp[i] = mini;
}

int minCut(string s){
    
    vector<int> dp(s.length(), -1);
    return f(0, s, dp) - 1;
}
};