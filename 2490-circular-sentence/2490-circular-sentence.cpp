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
        return ch == sentence[0];
    }
};