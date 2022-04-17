class Solution {
public:
    
    string digitSum(string s, int k) {
        
        while(1)
        {
            if(s.size() <= k)
                break;
                int p = 0 ,sum = 0 , temp = 0;
                string t = "";
            for(int i = 0 ; i < s.size() ; i++)
            {
                sum += (s[i] - '0');
                temp++;
                if(k == temp)
                {
                    t += to_string(sum);
                    sum = 0;
                    temp = 0;
                }
            }
            
            if(temp)
            {
                t += to_string(sum);
            }
            s = t;
    }
        
        string ans ="";
        for(auto x : s)
            ans += x;
        return ans;
    }
};