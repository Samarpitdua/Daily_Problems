class Logger {
public:
    map<string , int> mp;
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(mp.find(message) == mp.end())
        {
            mp[message] = timestamp;
            return true;
        }
        else
        {
            if(abs(mp[message] - timestamp) < 10)
                return false;
            mp[message] = timestamp;
            return true;
        }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */