class Solution {
public:
    string getPermutation(int n, int k) {
        string ans = "";
        long long int fact = 1;
        vector<int> temp;
        for(int i = 1 ; i < n ;i++)
        {
            fact = fact * i;
            temp.push_back(i);
        }
        temp.push_back(n);
        k--;
        while(1)
        {
            ans += to_string(temp[k / fact]);
            temp.erase(temp.begin() + k / fact);
            if(ans.size() == n)
                break;
            k = k % fact;
            fact /= (temp.size());
        }
        return ans;
    }
};