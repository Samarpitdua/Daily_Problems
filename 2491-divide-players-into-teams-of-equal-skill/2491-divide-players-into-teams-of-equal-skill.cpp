class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin() , skill.end());
        int n = skill.size();
        int sum = skill[0] + skill[n - 1];
        
        long long ans = 0;
        ans += skill[0] * skill[n - 1];
        for(int i = 1 , j = n - 2; i  < j ;i++ , j--){
            if(skill[i] + skill[j] == sum)
            {
                ans += skill[i] * skill[j];
            }
            else
                return -1;
        }
        return ans;
    }
};