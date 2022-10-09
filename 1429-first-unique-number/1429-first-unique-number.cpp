class FirstUnique {
public:
    map<int , int> mp;
    queue<int> q;
    FirstUnique(vector<int>& nums) {
        for(auto x : nums)
        {
            q.push(x);
            mp[x]++;
        }
    }
    
    int showFirstUnique() {
        while(!q.empty() and mp[q.front()] > 1)
            q.pop();
        if(q.empty())
            return -1;
        return q.front();
    }
    
    void add(int x) {
        q.push(x);
        mp[x]++;
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */