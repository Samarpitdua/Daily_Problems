class Solution {
public:
    string reorderSpaces(string text) {
        vector<string> ans;
        int ct = 0;
        for(auto x : text)
        {
            if(x == ' ')
                ct++;
        }
        string t = "";
        for(int i = 0 ; i < text.size() - 1 ; i++)
        {
            if(text[i] != ' ' and text[i + 1] == ' ')
            {
                t += text[i];
                ans.push_back(t);
                t = "";
            }
            else if(text[i] != ' ' and text[i + 1] != ' ')
                t += text[i];
        }
    //    cout<<ct<<" ";
        if(text[text.size() - 1] != ' ')
            t += text[text.size() - 1];
        string temp = "";
        if(t != "")
            ans.push_back(t);
        int tem;
        if(ans.size() == 1)
            tem = ct;
        else
        {tem = ct % (ans.size() - 1);
        ct = ct / (ans.size() - 1);}
        
        for(int i = 0 ; i < ans.size() - 1 ; i++)
        {
            temp += ans[i];
            for(int i = 0 ; i < ct ;i++)
            {
                temp += ' ';
            }
        }
       // cout<<tem<<endl;
        temp += ans[ans.size() - 1];
        while(tem>0)
            temp += ' ',tem--;
        return temp;
    }
};