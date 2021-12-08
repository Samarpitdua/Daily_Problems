class Solution {
public:
    int maxDepth(string s) {
        int open = 0;
        int ans = 0 ;
        for(int i = 0;i<s.size();i++)
        {
            if(s[i] == '(')open++;
            else if(s[i] == ')')open--;
            ans = max(ans, open);
            
        }
        return ans;
        
    }
};
