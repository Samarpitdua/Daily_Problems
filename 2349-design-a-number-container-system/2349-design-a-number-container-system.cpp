class NumberContainers {
public:
    unordered_map<int , int> mp;
    map<int , set<int>> mp2;
    
    NumberContainers() {
        mp.clear();
        mp2.clear();
    }
    void change(int index, int number) {
        auto it = mp.find(index);
        if (it != end(mp))
            mp2[it->second].erase(index);
        mp[index] = number;
        mp2[number].insert(index);
    }
    int find(int number) {
        auto it = mp2.find(number);
        return it == end(mp2) || it->second.empty() ? -1 : *begin(it->second);
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */