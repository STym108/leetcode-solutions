class Twitter {
public:
unordered_map<int,unordered_set<int>>followingmp;
unordered_map<int,unordered_set<int>>user_tweetmp;
int tweetorder=0;
unordered_map<int,int>order_tweetmp;
    Twitter() {}
    
    void postTweet(int userid, int tweetid) {
    // followingmp[userid].insert(userid);
    order_tweetmp[tweetorder]=tweetid;
    user_tweetmp[userid].insert(tweetorder);
    tweetorder++;
    }
    
    vector<int> getNewsFeed(int userId) {
    vector<int>ans;
    unordered_set<int> finalusers;
    priority_queue<int>pq;
    finalusers.insert(userId);

    for(auto listt:followingmp){
    int userr=listt.first;

    if(followingmp[userr].find(userId)!=followingmp[userr].end()){
        // for(auto twts:tweetsmp[userr]) temp.push_back(twts);
        finalusers.insert(userr);
    }
    }
    for(auto u:finalusers){
    for(auto t:user_tweetmp[u]){ pq.push(t); }
    }
    int q=0;
    while(pq.size()&&q<10){
    ans.push_back(order_tweetmp[pq.top()]);
    pq.pop();
    q++;
    }
return ans;
    
    }
    
    void follow(int followerId, int followeeId) {
        followingmp[followeeId].insert(followerId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followingmp[followeeId].erase(followerId);
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