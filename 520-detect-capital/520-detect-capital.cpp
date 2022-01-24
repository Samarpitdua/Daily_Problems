class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size() == 1)
            return true;
        int low , high;
        low = high = 0;
        if(word[0] >= 'a' and word[0] <= 'z')
            low = 1;
        else if(word[1] >= 'a' and word[1] <= 'z')
            low = 1;
        else
            high = 1;
        if(high){
        for(int i = 1 ; i < word.size() ;i++)
        {
            if(word[i] >= 'A' and word[i] <= 'Z')
                continue;
            return false;
        }
        }
        else{
        for(int i = 1 ; i < word.size() ;i++)
        {
            if(word[i] >= 'a' and word[i] <= 'z')
                continue;
            return false;
        }
        }
        return true;
    }
};