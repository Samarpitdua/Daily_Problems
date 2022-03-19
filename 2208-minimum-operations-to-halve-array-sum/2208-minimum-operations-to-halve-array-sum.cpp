class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        int n = nums.size() , ct = 0;
        double sum = 0 , ans = 0;
        for(int i = 0 ; i < n ;i++)
        {
            pq.push(nums[i]);
            sum += nums[i];
        }
        ans = sum;
        
        while(ans > (sum / 2.0))
        {
            double temp = pq.top();
            pq.pop();
            ans -= (temp/2.0);
            //cout<<ans<<" ";
            pq.push(temp/2.0);
            ct++;
        }
        cout<<endl;
        return ct;
    }
};