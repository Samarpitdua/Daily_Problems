class LRUCache {
public:
    class node{
        public : 
            int key;
            int val;
            node* next , *prev;
            node(int _key , int _val)
            {
                key = _key;
                val = _val;
                next = NULL;
                prev = NULL;
            }
    };
    int cap;
    node* head = new node(-1 , -1);
    node* tail = new node(-1 , -1);
    unordered_map<int , node*> mp;
    LRUCache(int capacity) {
        cap = capacity;
        head -> next = tail;
        tail -> prev = head;
        
    }
    void remove(int key)
    {
        node* todel = mp[key];
        node* temp = todel -> next;
        node* temp2 = todel -> prev;
        temp2 -> next = temp;
        temp -> prev = temp2;
        mp.erase(key);
    }
    void add(node* toadd)
    {
        node* temp = head -> next;
        head -> next = toadd;
        toadd -> next = temp;
        temp -> prev = toadd;
        toadd -> prev = head;
    }
    int get(int key) {
        if(mp.find(key) == mp.end())
        {
            return -1;
        }
        else
        {
            node* newnode = new node(key , mp[key] -> val);
            remove(key);
            add(newnode);
            mp[key] = newnode;
            return mp[key] -> val;
        }
    }
    
    void put(int key, int value) {
        node* newnode = new node(key , value);
        if(mp.find(key) == mp.end())
        {
            
            if(cap)
            {
                // mp[key] = newnode;
                add(newnode);
                cap--;
            }
            else
            {
                remove(tail -> prev -> key);
                add(newnode);
                
            }
            // cout<<mp.size()<</val<<" ";
        }
        else
        {
            remove(key);
            add(newnode);
        }
        mp[key] = newnode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */