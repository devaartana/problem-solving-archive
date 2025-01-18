class Twitter {
public:
    std::unordered_map<int, std::unordered_set<int>> following;
    std::vector<std::pair<int, int>> tweets;

    Twitter() { tweets = std::vector<std::pair<int, int>>(); }

    void postTweet(int userId, int tweetId) {
        tweets.push_back({userId, tweetId});
    }

    std::vector<int> getNewsFeed(int userId) {
        std::vector<int> ans;

        int i = tweets.size() - 1;
        while (ans.size() < 10 && i >= 0) {

            auto temp = &following[userId];
            if (userId == tweets[i].first ||
                temp->find(tweets[i].first) != temp->end()) {
                ans.push_back(tweets[i].second);
            }
            i--;
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
