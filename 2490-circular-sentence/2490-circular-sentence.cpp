class Solution {
public:
    bool isCircularSentence(string sentence) {
        stringstream ss(sentence);
        string temp;
        char ch = '#';
        while(ss >> temp)
        {
            int n = temp.size();
            if(ch == '#')
            {
                ch = temp[n - 1];
            }
            else
            {
                if(temp[0] == ch)
                {
                    ch = temp[n - 1];
                }
                else
                    return false;
            }
        }
        if(ch == sentence[0])
            return 1;
        return 0;
    }
};