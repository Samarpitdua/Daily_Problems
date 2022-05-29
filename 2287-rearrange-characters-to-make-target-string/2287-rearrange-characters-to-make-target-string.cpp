class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> freq1(26 , 0) , freq2(26 , 0);
        for(auto x : s) 
            freq1[x - 'a']++;
        for(auto x : target)
            freq2[x - 'a']++;
        int maxi = INT_MAX;
        for(int i = 0 ; i < 26 ; i++)
        {
            if(freq2[i] > 0)
                maxi = min(freq1[i] / freq2[i] , maxi);
        }
        return maxi;
    }
};