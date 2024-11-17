#include <bits/stdc++.h>
using namespace std;

/*  
Design Twitter
===================== 
    follow(followerId, followerDD)
            userId       otherId

    unfollow (userId ,    otherId )     

    getNewsFeed -> userTweet     recejt <- priority queue (time)
                -> other userTweet which other user follow

    post -> userid , tweet id

    D.S. we use -> unordered map < int , unorder_map <int, int>> folow

    vector <pair < int     ,    int > < post
                    userid     tweet id

    back element pushed is recent
*/

class Twitter {
    unordered_map<int, unordered_set<int>> follows;
    vector<pair<int, int>> posts;
public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        posts.push_back({userId, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        int count = 0;
        for (int i = posts.size() - 1; i >= 0 && count < 10; i--) 
            if (posts[i].first == userId || follows[userId].count(posts[i].first)) {
                feed.push_back(posts[i].second);
                count++;
            } //  here we will iterating backwards of vector because recent one pushed in back
            // But we can also use timeline with pq  max heap
        
        return feed;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            follows[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};

int main() {
    Twitter twitter;

    twitter.postTweet(1, 5);
    twitter.postTweet(1, 3);
    twitter.postTweet(1, 101);
    twitter.postTweet(1, 13);
    twitter.postTweet(1, 10);
    twitter.postTweet(1, 2);
    twitter.postTweet(1, 94);
    twitter.postTweet(1, 505);
    twitter.postTweet(1, 333);
    twitter.postTweet(1, 22);
    twitter.postTweet(1, 11);

    vector<int> newsFeed = twitter.getNewsFeed(1);
    for (int tweetId : newsFeed)   cout << tweetId << " ";
    
    cout << endl;

    twitter.follow(1, 2);
    twitter.postTweet(2, 6);
    newsFeed = twitter.getNewsFeed(1);
    for (int tweetId : newsFeed)   cout << tweetId << " ";
    
    cout << endl;

    twitter.unfollow(1, 2);
    newsFeed = twitter.getNewsFeed(1);
    for (int tweetId : newsFeed) cout << tweetId << " ";
    
    cout << endl;

    return 0;
}


