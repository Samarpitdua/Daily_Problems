class Solution {
public:
    void solve(string digits , vector<string>& ans , string s , int i , int n)
    {
        if(i == n)
        {
            ans.push_back(s);
            return;
        }
        if(digits[i] == '2')
        {
            solve(digits , ans , s + 'a' , i + 1 , n);
            solve(digits , ans , s + 'b' , i + 1 , n);
            solve(digits , ans , s + 'c' , i + 1 , n);
        }
        else if(digits[i] == '3')
        {
            solve(digits , ans , s + 'd' , i + 1 , n);
            solve(digits , ans , s + 'e' , i + 1 , n);
            solve(digits , ans , s + 'f' , i + 1 , n);
        }
        else if(digits[i] == '4')
        {
            solve(digits , ans , s + 'g' , i + 1 , n);
            solve(digits , ans , s + 'h' , i + 1 , n);
            solve(digits , ans , s + 'i' , i + 1 , n);
        }
        else if(digits[i] == '5')
        {
            solve(digits , ans , s + 'j' , i + 1 , n);
            solve(digits , ans , s + 'k' , i + 1 , n);
            solve(digits , ans , s + 'l' , i + 1 , n);
        }
        else if(digits[i] == '6')
        {
            solve(digits , ans , s + 'm' , i + 1 , n);
            solve(digits , ans , s + 'n' , i + 1 , n);
            solve(digits , ans , s + 'o' , i + 1 , n);
        }
        else if(digits[i] == '7')
        {
            solve(digits , ans , s + 'p' , i + 1 , n);
            solve(digits , ans , s + 'q' , i + 1 , n);
            solve(digits , ans , s + 'r' , i + 1 , n);
            solve(digits , ans , s + 's' , i + 1 , n);
        }
        else if(digits[i] == '8')
        {
            solve(digits , ans , s + 't' , i + 1 , n);
            solve(digits , ans , s + 'u' , i + 1 , n);
            solve(digits , ans , s + 'v' , i + 1 , n);
        }
        else
        {
            solve(digits , ans , s + 'w' , i + 1 , n);
            solve(digits , ans , s + 'x' , i + 1 , n);
            solve(digits , ans , s + 'y' , i + 1 , n);
            solve(digits , ans , s + 'z' , i + 1 , n);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string s = "";
        if(digits.size() == 0)
            return ans;
        solve(digits , ans , s , 0 , digits.size());
        return ans;
    }
};