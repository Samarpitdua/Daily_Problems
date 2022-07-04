class Solution {
public:
    unordered_map<string , bool> mp;
    
    bool wordBreak(string s, vector<string>& words)
    {
        if(find(words.begin() , words.end() , s) != words.end())
            return true;
        if(mp.find(s) != mp.end())
            return mp[s];
        for(int i = 1 ; i < s.size() ; i++)
        {
            string curr = s.substr(0 , i);
            if(find(words.begin() , words.end() , curr) != words.end())
            {
                
                if(wordBreak(s.substr(i , s.size()) , words))
                {
                    mp[s] = true;
                    return true;
                }
            }
          
        }
        mp[s] = false;
        return false;
        
    }
};