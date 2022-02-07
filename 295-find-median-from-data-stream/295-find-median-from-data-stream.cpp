class MedianFinder {
public:
    priority_queue<double> left;
    priority_queue<double , vector<double> , greater<double> > right; 
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.empty())
            left.push(num);
        else
        {
            if(num > left.top())
                right.push(num);
            else
                left.push(num);
        }
        if((left.size()) > right.size() + 1)
        {
            int temp = left.top();
            left.pop();
            right.push(temp);
        }
        else if((right.size()) > left.size() + 1)
        {
            int temp = right.top();
            right.pop();
            left.push(temp);
        }
    }
    
    double findMedian() {
        if(left.size() > right.size())
            return left.top();
        else if(left.size() < right.size())
            return right.top();
        else
        {
            cout<<left.top()<<" "<<right.top()<<"\n";
            double ans = (left.top() + right.top()) / double(2);
            return ans;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */