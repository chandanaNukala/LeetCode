class Twitter {
private:
    int counter;
    unordered_map<int,vector<pair<int,int>>>tweetMap;
    unordered_map<int,unordered_set<int>>followMap;
public:
    Twitter() {
        counter=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({counter++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>>pq;
        followMap[userId].insert(userId);

        for(int followeeId:followMap[userId]){
            const auto& userTweets=tweetMap[followeeId];
            for(const auto&t:userTweets){
                pq.push(t);
            }
        }

        vector<int>result;
        int cnt=0;
        while(!pq.empty() && cnt<10){
            result.push_back(pq.top().second);
            pq.pop();
            cnt++;
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId==followeeId)return;
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId==followeeId)return;
        followMap[followerId].erase(followeeId);
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