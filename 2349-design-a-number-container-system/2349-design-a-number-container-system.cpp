class NumberContainers {
public:
    unordered_map<int , int> mp;
    map<int , set<int>> mp2;
    
    NumberContainers() {
        mp.clear();
        mp2.clear();
    }
    
    void change(int index, int number) {
        if(mp.find(index) != mp.end()){
            int val = mp[index];
            mp2[val].erase(index);
        }
        mp[index] = number;
         mp2[number].insert(index);
    }
    
    int find(int number) {
        if(mp2.find(number) != mp2.end()){
            for(auto x : mp2[number])
                return x;
        }
        else
            return -1;
       return -1; 
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */