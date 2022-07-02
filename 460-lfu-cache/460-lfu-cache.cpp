class LFUCache {
public:
    struct Node
    {
        int val , key , ct;
        Node* next;
        Node* prev;
        Node(int key , int value)
        {
            val = value;
            this -> key = key;
            ct = 1;
        }
    };
    struct List
    {
        int sz;
        Node* head;
        Node* tail;
        List()
        {
            head = new Node(-1 , -1);
            tail = new Node(-1 , -1);
            head -> next = tail;
            tail -> prev = head;
            sz = 0;
        }
        void add(Node* node)
        {
            Node* temp = head -> next;
            head -> next = node;
            node -> next = temp;
            node -> prev = head;
            temp -> prev = node;
            sz++;
        }
        void remove(Node* delnode)
        {
            Node* temp = delnode -> prev;
            Node* temp2 = delnode -> next;
            temp -> next = temp2;
            temp2 -> prev = temp;
            sz--;
        }
        
    };
    map<int , Node*> keyNode;
    map<int , List*> freq;
    // keyNode.clear();
    // freq.clear();
    
    int maxSize , minFreq , curSize;
    LFUCache(int capacity) {
        maxSize = capacity;
        minFreq = 0;
        curSize = 0;
    }
    void updateFreqListMap(Node* node)
    {
        keyNode.erase(node -> key);
        freq[node -> ct] -> remove(node);
        if(node -> ct == minFreq and freq[node -> ct] -> sz == 0)
            minFreq++;
        List* nextHigherFreqList = new List();
        if(freq.find(node -> ct + 1) != freq.end())
        {
            nextHigherFreqList = freq[node -> ct + 1];
        }
        node -> ct += 1;
        nextHigherFreqList -> add(node);
        freq[node -> ct] = nextHigherFreqList;
        keyNode[node -> key] = node;
    }
    int get(int key) {
        if(keyNode.find(key) == keyNode.end())
            return -1;
        Node* temp = keyNode[key];
        int ans = temp -> val;
        // for(auto x : keyNode)
        //     cout<<x.first;
        // cout<<temp -> val<<endl;
        updateFreqListMap(temp);
        return ans;
    }
    
    void put(int key, int value) {
        if(maxSize == 0)          //if capacity is 0
            return;
        if(keyNode.find(key) == keyNode.end())
        {
            if(curSize == maxSize)
            {
               List* list = freq[minFreq];
                keyNode.erase(list -> tail -> prev -> key);
                freq[minFreq] -> remove(list -> tail -> prev);
                curSize--;
            }
            curSize++;
            minFreq = 1;
            List* listfreq = new List();
            if(freq.find(minFreq) != freq.end())
                listfreq = freq[minFreq];
            // cout<<value<<" ";
            Node* node = new Node(key , value);
            // cout<<node -> val<<" ";
            listfreq -> add(node);
            keyNode[key] = node;
            freq[minFreq] = listfreq;
            // cout<<node -> val<<" ";
        }
        else
        {
            Node* node = keyNode[key];
            node -> val = value;
            cout<<node -> val;
            updateFreqListMap(node);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */