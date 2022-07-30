class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int freq2[26] = {0};
        for(auto y : words2)
        {
            int freq[26] = {0}; 
            for(auto x : y){
            freq[x - 'a']++;
            if(freq2[x - 'a'] < freq[x - 'a'])
                freq2[x - 'a']++;
            }
        }
        vector<string> ans;
        for(auto y : words1)
        {
            int freq[26] = {0}; 
            for(auto x : y)
            {
                freq[x - 'a']++;
            }
            int p = 0;
            for(int i = 0 ; i < 26 ;i++)
            {
                if(freq[i] < freq2[i])
                {
                    p = 1;
                    break;
                }
            }
            if(!p)
                ans.push_back(y);
        }
        return ans;
        
        
    }
};