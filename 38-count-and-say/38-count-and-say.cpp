class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        string temp = "1";
        for(int i = 1 ; i < n ;i++)
        {
            string temp2 = "";
            int ct = 0;
            for(int j = 0 ; j < temp.size() ;j++)
            {
                if(j < temp.size() - 1 and temp[j] == temp[j + 1])
                    ct++;
                else
                {
                    ct++;
                    temp2 += to_string(ct) + temp[j];
                    ct = 0;
                }
            }
            temp = temp2;
        }
        return temp;
    }
};