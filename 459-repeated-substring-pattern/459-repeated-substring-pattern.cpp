class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string temp = s + s;
        temp = temp.substr(1);
        temp.pop_back();
        // cout<<temp<<" ";
        if(temp.find(s) != string ::npos)
            return true;
        return false;
            
    }
};