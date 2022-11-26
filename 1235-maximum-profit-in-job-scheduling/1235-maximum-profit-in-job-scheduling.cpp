class Solution {
public:
    int a[50005];
    struct job{
        int st,end,value;
    };
    //static function can be called using class name and :: we do not need object to call it and it is initialized once.
    static bool comp(job a,job b){ 
        return (a.end < b.end);
    }
    int get_profit(job arr[],int i){
        if(i<0)
        return 0;
        if(a[i]!=-1)
            return a[i];
        int j=i-1;
        while(j>=0 && arr[j].end>arr[i].st)  //search for the nearest possible position
        j--;
        
        return a[i]=max(arr[i].value+get_profit(arr,j), get_profit(arr,i-1));
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        memset(a,-1,sizeof(a));
        job arr[n];
        for(int i=0;i<n;i++){
            arr[i].st=startTime[i];
            arr[i].end=endTime[i];
            arr[i].value=profit[i];
        }
        sort(arr,arr+n,comp);
        return get_profit(arr,n-1);
    }
};