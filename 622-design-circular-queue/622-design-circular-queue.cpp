class MyCircularQueue {
public:
    vector<int> v;
    int front = -1 , rear = -1;
    MyCircularQueue(int k) {
        v.resize(k);
    }
    
    bool enQueue(int value)
    {
        if(front == -1 and rear == -1)
        {
            front = 0 , rear = 0;
            v[rear] = value;
            return true;
     //       continue;
        }
        else if(isFull())
            return false;
        else if(rear == v.size() - 1)
            rear = 0;
        else
            rear++;
        v[rear] = value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())
            return false;
        if(rear == front)
            rear = -1 , front = -1;
        else if(front == v.size() - 1)
            front = 0;
        else
            front++;
        return true;
    }
    
    int Front() {
        if(isEmpty())
            return -1;
        else
            return v[front];
    }
    
    int Rear() {
        if(isEmpty())
            return -1;
        else
            return v[rear];
        
    }
    
    bool isEmpty() {
        if(rear == -1)
            return true;
        return false;
    }
    
    bool isFull() {
        if(rear + 1 == front or (rear == v.size() - 1 and front == 0))
            return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */