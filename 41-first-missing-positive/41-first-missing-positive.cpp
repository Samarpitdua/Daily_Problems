class Solution {
public:
    int firstMissingPositive(vector<int>& a) {
        int n = a.size();
        for(int i = 0 ; i < n ;){
            if(a[i] > 0 and a[i] <= n and a[i] != i + 1 and a[a[i] - 1] != (a[i])){
                swap(a[i] , a[a[i] - 1]);
            }
            else{
                i++;
            }
        }
        for(int i = 0 ; i < n ;i++){
            if(a[i] != i + 1)
                return (i + 1);
        }
        return n + 1;
    }
};