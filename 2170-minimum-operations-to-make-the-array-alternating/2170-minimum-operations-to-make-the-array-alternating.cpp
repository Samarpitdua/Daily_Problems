struct comp
{
    bool operator()(pair<int,int> x , pair<int,int> y)
    {
        return x.second < y.second;
    }
};
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        map<int , int> mp , mp2;
        int n = nums.size();
        if(n == 1)
            return 0;
        for(int i = 0 ; i < nums.size() ;i++)
        {
            if(i & 1)
                mp[nums[i]]++;
            else
                mp2[nums[i]]++;
        }
        priority_queue<pair<int , int> , vector<pair<int , int>> , comp> pq , pq2;
        for(auto x : mp)
        {
            pq.push({x.first , x.second});
           
        }
        for(auto x : mp2)
        {
            pq2.push({x.first , x.second});
           
        }
        int maxi2 = -1 , maxi4 = -1;
        int maxi1 = pq.top().first;
        pq.pop();
        if(!pq.empty())
         maxi2 = pq.top().first;
        int maxi3 = pq2.top().first;
        pq2.pop();
        if(!pq2.empty())
         maxi4 = pq2.top().first;
        int ans = 0;
        if(maxi1 != maxi3)
        {
           // cout<<maxi1<<" "<<maxi3<<" ";
            for(int i=0;i<n;i++)
            {
                if(i&1 and nums[i]!=maxi1)ans++;
                else if(i%2==0 and nums[i]!=maxi3)ans++;
            }
            //cout<<ans<<" ";
            return ans;
        }
        else
        {
            int ct1 = 0 , ct2 = 0;
            for(int i=0;i<n;i++)
            {
                if(i&1 and nums[i]!=maxi1)ct1++;
                else if(i%2==0 and nums[i]!=maxi4)ct2++;
            }
            ans = ct1+ct2;
            ct1=0 , ct2 = 0;
            for(int i=0;i<n;i++)
            {
                if(i&1 and nums[i]!=maxi2)ct1++;
                else if(i%2==0 and nums[i]!=maxi3)ct2++;
            }
            return min(ans , ct1 + ct2);
        }
        //cout<<maxi1<<" "<<maxi2<<" "<<maxi3<<" "<<maxi4;
        return 0;
        
    }
};