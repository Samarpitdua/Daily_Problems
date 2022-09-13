class MovingAverage {
public:
    int sum;
    int sz;
    queue<int> q;
    MovingAverage(int size) {
        sz = size;
        sum = 0.0;
    }
    
    double next(int val) {
        // cout<<sum<<" ";
        double ans = 0.0;
        if(q.size() < sz)
        {
            q.push(val);
            sum += val;
            ans = sum / (double)q.size();
        }
        else
        {
            sum -= q.front();
            q.pop();
            q.push(val);
            sum += val;
            ans = sum / (double)q.size();
        }
        return ans;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */