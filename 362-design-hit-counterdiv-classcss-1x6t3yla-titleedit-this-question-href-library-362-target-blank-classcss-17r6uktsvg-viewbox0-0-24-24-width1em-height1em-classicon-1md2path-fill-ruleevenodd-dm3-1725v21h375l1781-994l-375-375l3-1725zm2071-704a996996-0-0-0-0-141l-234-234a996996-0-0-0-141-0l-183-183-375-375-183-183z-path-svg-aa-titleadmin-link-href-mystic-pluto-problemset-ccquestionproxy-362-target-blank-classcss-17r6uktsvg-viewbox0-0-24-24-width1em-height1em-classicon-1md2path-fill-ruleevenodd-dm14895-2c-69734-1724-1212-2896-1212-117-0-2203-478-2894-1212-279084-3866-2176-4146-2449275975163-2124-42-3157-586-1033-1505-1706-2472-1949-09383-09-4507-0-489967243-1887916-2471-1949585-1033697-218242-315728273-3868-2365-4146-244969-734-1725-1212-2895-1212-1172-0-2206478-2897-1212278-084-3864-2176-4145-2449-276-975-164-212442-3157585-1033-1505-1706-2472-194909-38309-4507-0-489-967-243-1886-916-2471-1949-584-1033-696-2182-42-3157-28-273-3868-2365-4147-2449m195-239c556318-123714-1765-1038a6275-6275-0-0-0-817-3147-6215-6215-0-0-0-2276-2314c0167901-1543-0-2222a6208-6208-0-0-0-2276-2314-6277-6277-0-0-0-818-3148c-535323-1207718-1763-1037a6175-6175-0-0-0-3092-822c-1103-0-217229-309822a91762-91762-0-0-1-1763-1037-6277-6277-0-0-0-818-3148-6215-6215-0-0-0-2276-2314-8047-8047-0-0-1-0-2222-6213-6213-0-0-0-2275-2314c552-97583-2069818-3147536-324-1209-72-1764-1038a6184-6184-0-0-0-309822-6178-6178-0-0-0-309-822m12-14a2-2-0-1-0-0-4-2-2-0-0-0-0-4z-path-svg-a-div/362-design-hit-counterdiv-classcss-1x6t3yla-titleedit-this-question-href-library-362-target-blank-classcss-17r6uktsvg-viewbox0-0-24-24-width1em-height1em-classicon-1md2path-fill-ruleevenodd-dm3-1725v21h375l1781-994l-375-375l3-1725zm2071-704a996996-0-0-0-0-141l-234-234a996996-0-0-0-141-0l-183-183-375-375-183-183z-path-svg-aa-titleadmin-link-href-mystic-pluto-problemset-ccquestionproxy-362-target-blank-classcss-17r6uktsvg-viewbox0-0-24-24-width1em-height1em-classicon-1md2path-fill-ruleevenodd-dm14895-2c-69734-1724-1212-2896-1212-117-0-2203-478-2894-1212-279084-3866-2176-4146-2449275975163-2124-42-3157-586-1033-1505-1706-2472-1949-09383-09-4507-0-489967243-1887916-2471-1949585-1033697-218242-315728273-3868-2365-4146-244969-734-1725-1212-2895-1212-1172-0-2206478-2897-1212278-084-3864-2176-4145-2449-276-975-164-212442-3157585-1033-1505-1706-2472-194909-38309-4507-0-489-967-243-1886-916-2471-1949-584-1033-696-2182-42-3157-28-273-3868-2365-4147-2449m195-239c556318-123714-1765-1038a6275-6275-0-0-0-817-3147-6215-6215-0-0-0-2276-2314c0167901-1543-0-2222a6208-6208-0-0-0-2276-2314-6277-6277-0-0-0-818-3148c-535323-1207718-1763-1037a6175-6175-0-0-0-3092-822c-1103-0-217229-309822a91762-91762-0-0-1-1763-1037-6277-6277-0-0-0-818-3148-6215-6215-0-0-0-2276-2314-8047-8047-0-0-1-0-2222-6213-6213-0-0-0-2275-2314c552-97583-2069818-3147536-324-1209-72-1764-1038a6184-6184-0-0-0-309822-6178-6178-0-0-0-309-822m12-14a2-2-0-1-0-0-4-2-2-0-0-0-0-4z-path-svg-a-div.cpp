class HitCounter {
vector<int> array;
    unordered_map<int, int> map;
public:
    /** Initialize your data structure here. */
    HitCounter() {
        
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        if(array.empty()) {
            map[timestamp] = 1;
        } else {
            map[timestamp] = map[array.back()] + 1;
        }
        array.push_back(timestamp);
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        if(array.empty())
            return 0;
        int start = timestamp <= 300 ? timestamp : timestamp - 300;            
        auto endit = std::lower_bound(array.begin(), array.end(), timestamp);
        if(timestamp <= 300) {
            //if end is not found, then return last element
            if(endit == array.end())
                return map[array.back()];
            //if what you found is > 300, decrement and send value
            if(*endit > 300) 
                --endit;
            return map[*endit];
        }
        auto startit = std::lower_bound(array.begin(), array.end(), start);  
        if(startit == array.end()) //if startit is end then endit is also end
            return 0;   
        
        int key = 0;        
        //if end isn't found(then fetch last element) OR if end is > timestamp, then minus the value
        if(endit == array.end()) {
            key = array.back();            
        } else {
            if(*endit != timestamp)
                --endit;
            key = *endit;                    
        }
        //if startit is > start
        if(*startit > start) {
            if(startit == array.begin()) {                
                if(endit != array.end()) {
                    return map[key]; //no need to minus the value
                } else {
                    return map[array.back()];
                }
            } else {
                --startit;
            }
        }
        return (map[key] - map[*startit]);        
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */