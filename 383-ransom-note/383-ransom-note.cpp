class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int>mp;
        for(int i=0;i<magazine.size();i++)
            mp[magazine[i]]++;
        for(int i=0;i<ransomNote.size();i++)
        {
            if(mp[ransomNote[i]])
                mp[ransomNote[i]]-=1;
            else return false;
                
        }
        return true;
    }
};