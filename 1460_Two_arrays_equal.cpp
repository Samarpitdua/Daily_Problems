class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
       int a[1002]={0},brr[1002]={0};
        for(int i=0;i<arr.size();i++)
            a[arr[i]]++;
        for(int i=0;i<target.size();i++)
            brr[target[i]]++;
        for(int i=0;i<1002;i++)
            if(a[i]!=brr[i])
                return false;
        return true;
        
    }
};
