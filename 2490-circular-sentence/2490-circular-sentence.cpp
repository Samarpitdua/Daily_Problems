class Solution {
public:
    bool isCircularSentence(string sentence) {
        stringstream ss(sentence);
        string temp;
        char ch = '#';
        while(ss >> temp)
        {
            int n = temp.size();
            if(ch != '#')
                if(temp[0] != ch)
                    return false;
             ch = temp[n - 1];
        }
        if(ch == sentence[0])
            return 1;
        return 0;
    }
};