class Solution {
public:
    unordered_map<string , string> mp;
    int i = 1;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string s = to_string(i);
        i++;
        mp[s] = longUrl;
        return s;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string s) {
        string ans =  mp[s];
        return ans;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));