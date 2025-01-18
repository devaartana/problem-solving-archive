class Twitter {
public:
    std::unordered_map<int, std::unordered_set<int>> following;
    std::unordered_map<int, std::vector<std::pair<int, int>>> tweets;
    int count;

    Twitter() { count = 0; }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({count++, tweetId});
    }

    std::vector<int> getNewsFeed(int userId) {
        std::vector<int> ans;
        std::priority_queue<std::pair<int, int>> pq;

        for (int followed : following[userId]) {
            for (auto& tweet : tweets[followed]) {
                pq.push(tweet);
            }
        }

        for (auto& tweet : tweets[userId]) {
            pq.push(tweet);
        }

        while (ans.size() < 10 && !pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
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
