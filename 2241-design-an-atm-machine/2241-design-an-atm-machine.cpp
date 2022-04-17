class ATM {
public:
    priority_queue<int> pq;
    vector<long long int> v;
    int arr[5] = {20 ,50 ,100 ,200 ,500};
    ATM() {
        v.resize(5);
        for(int i = 0 ; i < 5;i++)
            v[i] = 0;
        
    }
    
    void deposit(vector<int> b) {
        for(int i = 0 ; i < 5 ; i++)
            v[i] += b[i];
    }
    
    vector<int> withdraw(int amount) 
    {
        int ct = amount;
        vector<long long int> v2(5);
        v2 = v;
        vector<int> ans(5 , 0);
        for(int i = 4 ; i >= 0 ;i--)
        {
            if(amount == 0)
            {
                v = v2;
                return ans;
            }
            if(v2[i])
            {
                long long multi = (long long)v2[i]*(long long)arr[i];
                if((v2[i]) >= (amount/arr[i]))
                {
                    int left = amount%arr[i];
                    v2[i] -= (amount/arr[i]);
                    ans[i]=(amount/arr[i]);
                    amount = left;
                }
                else
                {
                    int left = amount - (multi);
                    ans[i]=(v2[i]);
                    v2[i] = 0;
                    amount = left;
                    continue;
                }
            }
        }
        if(amount == 0)
            {
                v = v2;
                return ans;
            }
        else
        {
            vector<int> y;
            y.push_back(-1);
            return y;
        }
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */