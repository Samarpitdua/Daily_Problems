class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        deque<int>dq;
        for(int i=0;i<tickets.size();i++)
        {
            if(i==k)
                dq.push_front(-tickets[i]);
            else
            dq.push_front(tickets[i]);
        }
        int ct=0;
        while(1){
            ct++;
            
            int ans=dq.back();
            dq.pop_back();
            if(ans<0)
            {
                ans++;
                if(ans==0)
                    return ct;
                else
                    dq.push_front(ans);
            }
            else{
            ans--;
            if(ans>0)
                dq.push_front(ans);
            }
            
        }
        return ct;
        
        
    }
};
