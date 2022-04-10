class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int , vector<int> , greater<int>> pq;
        long long ans = 1;
        for(auto x : nums)
        {
            pq.push(x);
        }
        while(k > 0)
        {
            int temp = pq.top();
          //  cout<<temp <<" ";
            pq.pop();
            temp++;
            pq.push(temp);
            k--;
        }
        while(!pq.empty())
        {
            
            ans = ans * (pq.top() % 1000000007);
            ans = ans % 1000000007;
            pq.pop();
        }
        return ans;
    }
};