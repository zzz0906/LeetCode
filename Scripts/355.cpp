class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() { 
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        ID.insert(userId);
        post_user[userId].insert(tweetId);
        // for (int i = 0; i < followee_follower[userId].size(); i++){
        //     post_user[followee_follower[userId][i]].insert(tweetId);
        // }
        post_order.push_back(tweetId);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        vector<int> tmp;
        unordered_set<int> all_posts;
        for (auto & post : post_user[userId]) {
            all_posts.insert(post);
        }
        for (auto f_id:follower_followee[userId]){
            for (auto & post : post_user[f_id])
                all_posts.insert(post);
        }
        for (int i = 0; i < post_order.size(); i++) {
            if (all_posts.count(post_order[i])){
                tmp.push_back(post_order[i]);
            }
        }
        int j = tmp.size() - 1;
        
        while (j >= 0 && j > int(tmp.size() - 11)){
            res.push_back(tmp[j]);
            j--;
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        ID.insert(followerId);
        ID.insert(followeeId);
        bool find = false;
        for (int i = 0; i < follower_followee[followerId].size(); i++)
            if (follower_followee[followerId][i] == followeeId){
                find = true;
            }
        if (find) return;
        follower_followee[followerId].push_back(followeeId);
        // for (auto & ele : post_user[followerId])
        //     post_user[followeeId].insert(ele);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (!ID.count(followeeId) || !ID.count(followeeId))
            return;
        int pos = -1;
        for (int i = 0; i < follower_followee[followerId].size(); i++)
            if (follower_followee[followerId][i] == followeeId){
                pos = i;
                break;
            }
        if (pos != -1)
            follower_followee[followerId].erase(follower_followee[followerId].begin() + pos);
        else
            return;
        // for (auto & ele: post_user[followerId]){
        //     if (post_user[followeeId].count(ele)){
        //         post_user[followerId].erase(ele);
        //     }
        // }
    }
private:
    map<int, vector<int>> follower_followee;
    unordered_set<int> ID;
    map<int,unordered_set<int>> post_user;
    vector<int> post_order;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */