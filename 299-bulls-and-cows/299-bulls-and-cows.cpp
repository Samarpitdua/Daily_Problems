class Solution {
public:
    string getHint(string secret, string guess) {
        map<int , int> mp , mp2;
        string ans = "";
        int n = secret.size() , b = 0 , c = 0;
        for(int i = 0 ; i < n ;i++){
            if(secret[i] == guess[i])
            {
                mp[i]++;
                b++;
            }
        }
        for(int i = 0 ; i < n ;i++)
        {
            if(mp.find(i) == mp.end()){
                mp2[secret[i]]++;
            }
        }
        for(int i = 0 ; i < n ;i++)
        {
            if(mp.find(i) == mp.end() and mp2.find(guess[i]) != mp2.end())
            {
                if(mp2[guess[i]] > 0)
                    mp2[guess[i]]-- , c++;
            }
        }
        ans += to_string(b) + "A" + to_string(c) + "B";
        return ans;
    }
};