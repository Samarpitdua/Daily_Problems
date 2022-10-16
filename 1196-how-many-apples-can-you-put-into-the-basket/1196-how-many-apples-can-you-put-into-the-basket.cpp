class Solution {
public:
    int maxNumberOfApples(vector<int>& weight) {
        sort(weight.begin() , weight.end());
        long long int sum = 0 , ct = 0;
        for(auto x : weight){
            sum += x;
            if(sum > 5000)
            {
                return ct;
            }
            ct++;
        }
        return ct;
    }
};