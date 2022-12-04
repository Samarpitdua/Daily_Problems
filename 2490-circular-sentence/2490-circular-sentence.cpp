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
                
            }
            else
            {
                if(temp[0] == ch)
                {
                    
                }
                else
                    return false;
            }
             ch = temp[n - 1];
        }
        if(ch == sentence[0])
            return 1;
        return 0;
    }
};