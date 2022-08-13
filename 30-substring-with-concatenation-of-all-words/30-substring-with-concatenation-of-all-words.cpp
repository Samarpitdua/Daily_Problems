class Solution {
public:
vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> ump;
        for (string word : words)
            ump[word]++;
        int n = s.length(), num = words.size(), len = words[0].length();
        vector<int> indexes;
        for (int i = 0; i < n - num * len + 1; i++) 
        {
            unordered_map<string, int> seen;
            int j = 0;
            for (; j < num; j++) 
            {
                string word = s.substr(i + j * len, len);
                    if (ump.find(word) != ump.end()) 
                    {
                        seen[word]++;
                        if (seen[word] > ump[word])
                        break;
                    }
                    else
                    break;
            }
            if (j == num)
                indexes.push_back(i);
        }
        return indexes;
}
};

