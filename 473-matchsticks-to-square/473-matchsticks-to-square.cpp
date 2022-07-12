class Solution {
public:
    bool solve(int temp1 , int temp2 , int temp3 , int temp4 , int sum , vector<int>& m  , int ind){
        if(temp1 == sum and temp2 == sum and temp3 == sum){
                return true;
            }
        if(ind == m.size()){
            return false;
        }
        int a = 0 , b = 0 , c= 0 , d = 0;
if(temp1 + m[ind] <= sum)
    a = solve(temp1 + m[ind] , temp2 , temp3 ,temp4 , sum , m , ind + 1);
if(temp2 + m[ind] <= sum)
    b = solve(temp1, temp2  + m[ind] , temp3 ,temp4 ,sum , m , ind + 1);
if(temp3 + m[ind] <= sum)
    c = solve(temp1 , temp2 , temp3 + m[ind] , temp4 ,sum ,  m , ind + 1);
if(temp4 + m[ind] <= sum)
    d = solve(temp1 , temp2 , temp3 , temp4  + m[ind] ,sum ,  m , ind + 1);
        return a||b||c||d;
    }
    bool makesquare(vector<int>& m) {
        int temp1 = 0 , temp2 = 0 , temp3 = 0 , temp4 = 0 , sum = 0;
        sort(m.begin() , m.end() , greater<int>());
        for(auto x : m)
            sum += x;
        if(sum % 4 != 0){
            return false;
        }
        return solve(temp1 , temp2 , temp3 ,temp4 ,  sum / 4 , m , 0);
    }
};