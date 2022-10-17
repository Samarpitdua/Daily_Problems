class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        for(int i = 0 ; i < words.size() ;i++)
        {
            string t = "";
            for(int j = 0 ; j < words.size() ;j++)
            {
                if(words[j].size() > i)
                t += words[j][i];
            }
            if(t != words[i])
                return false;
        }
        return true;
    }
};