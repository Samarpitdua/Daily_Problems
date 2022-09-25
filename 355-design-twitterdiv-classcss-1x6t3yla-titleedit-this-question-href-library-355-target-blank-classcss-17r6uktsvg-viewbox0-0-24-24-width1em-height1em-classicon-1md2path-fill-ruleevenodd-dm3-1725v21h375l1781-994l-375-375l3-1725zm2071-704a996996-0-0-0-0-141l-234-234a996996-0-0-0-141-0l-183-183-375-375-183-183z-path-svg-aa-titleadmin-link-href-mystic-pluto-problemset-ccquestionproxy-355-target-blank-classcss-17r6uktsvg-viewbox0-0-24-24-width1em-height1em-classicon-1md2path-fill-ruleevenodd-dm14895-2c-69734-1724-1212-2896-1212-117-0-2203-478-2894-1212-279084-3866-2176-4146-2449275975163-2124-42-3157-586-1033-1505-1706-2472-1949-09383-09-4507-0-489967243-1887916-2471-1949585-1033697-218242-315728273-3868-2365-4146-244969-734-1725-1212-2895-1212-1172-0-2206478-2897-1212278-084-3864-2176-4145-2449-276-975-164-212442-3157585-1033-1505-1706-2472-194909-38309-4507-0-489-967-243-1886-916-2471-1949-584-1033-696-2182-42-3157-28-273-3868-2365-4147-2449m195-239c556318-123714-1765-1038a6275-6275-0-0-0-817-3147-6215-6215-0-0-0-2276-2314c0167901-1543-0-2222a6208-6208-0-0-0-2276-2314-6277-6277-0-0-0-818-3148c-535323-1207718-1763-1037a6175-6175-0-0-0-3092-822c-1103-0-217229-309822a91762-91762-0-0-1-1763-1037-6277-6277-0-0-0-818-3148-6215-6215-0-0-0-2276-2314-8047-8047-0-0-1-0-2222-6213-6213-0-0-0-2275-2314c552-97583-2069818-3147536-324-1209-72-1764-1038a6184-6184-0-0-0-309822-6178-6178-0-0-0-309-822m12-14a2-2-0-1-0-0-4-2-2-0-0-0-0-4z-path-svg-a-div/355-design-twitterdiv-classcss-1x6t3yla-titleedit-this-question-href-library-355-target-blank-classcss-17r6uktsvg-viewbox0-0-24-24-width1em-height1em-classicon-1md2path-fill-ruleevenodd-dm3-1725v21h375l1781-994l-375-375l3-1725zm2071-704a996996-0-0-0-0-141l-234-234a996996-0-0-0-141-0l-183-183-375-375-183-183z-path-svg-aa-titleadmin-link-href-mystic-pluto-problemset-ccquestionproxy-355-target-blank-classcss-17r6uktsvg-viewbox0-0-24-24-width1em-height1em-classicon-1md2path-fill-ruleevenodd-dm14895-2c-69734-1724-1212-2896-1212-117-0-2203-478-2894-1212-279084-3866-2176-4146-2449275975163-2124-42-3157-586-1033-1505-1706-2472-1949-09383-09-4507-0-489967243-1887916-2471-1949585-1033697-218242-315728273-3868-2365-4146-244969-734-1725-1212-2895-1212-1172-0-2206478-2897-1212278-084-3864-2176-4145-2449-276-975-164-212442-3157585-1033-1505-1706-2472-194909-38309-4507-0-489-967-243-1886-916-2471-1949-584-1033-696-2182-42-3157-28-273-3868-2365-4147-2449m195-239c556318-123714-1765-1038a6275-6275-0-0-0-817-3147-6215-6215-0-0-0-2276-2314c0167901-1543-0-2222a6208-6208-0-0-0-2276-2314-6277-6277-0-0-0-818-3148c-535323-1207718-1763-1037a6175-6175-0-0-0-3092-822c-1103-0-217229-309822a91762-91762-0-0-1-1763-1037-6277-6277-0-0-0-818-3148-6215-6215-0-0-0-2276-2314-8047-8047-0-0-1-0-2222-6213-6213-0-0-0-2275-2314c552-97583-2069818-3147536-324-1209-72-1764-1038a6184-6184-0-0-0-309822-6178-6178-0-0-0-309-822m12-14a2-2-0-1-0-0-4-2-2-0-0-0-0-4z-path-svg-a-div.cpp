class Twitter {
public:
    unordered_map<int , vector<pair<int , int>>> users;
    unordered_map<int , set<int>> follows;
    long long time;
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        time++;
        users[userId].push_back({time , tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int , int>> pq;
        for(auto x : users[userId])
        {
            pq.push(x);
        }
        for(auto x : follows[userId])
        {
            for(auto y : users[x])
            {
                pq.push(y);
            }
        }
        vector<int> ans;
        while(!pq.empty() and ans.size() < 10)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */