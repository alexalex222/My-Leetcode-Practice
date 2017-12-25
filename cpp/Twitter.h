using namespace std;
class Twitter {
private:
	struct tweet {
		int time;
		int id;
		tweet(int t, int d) {
			time = t;
			id = d;
		}

		bool operator<(tweet other) const {
			return time > other.time;
		}
	};
	unordered_map<int, queue<tweet>> userPost;
	unordered_map<int, set<int>> userRelation;
	int curTime;

	
public:
    /** Initialize your data structure here. */
    Twitter() {
        curTime = 0;
    }

    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
		tweet t = tweet(curTime, tweetId);
		curTime++;
		if(userPost.find(userId) == userPost.end()) {
			queue<tweet> tweets;
			tweets.push(t);
			userPost.emplace(userId, tweets);
		}
		else {
			if(userPost[userId].size() < 10 ) {
				userPost[userId].push(t);
			}
			else {
				userPost[userId].pop();
				userPost[userId].push(t);
			}
			
		}
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<tweet> allNewsFeed;
		queue<tweet> tempPost;
		vector<int> result;
		int feedSize = 10;
		int i = 0;
		if(userRelation.find(userId) == userRelation.end()) {
			set<int> followeeList;
			followeeList.emplace(userId);
			userRelation.emplace(userId, followeeList);
		}
		for(int followeeId : userRelation[userId]) {
			if(userPost.find(followeeId) != userPost.end()) {
				tempPost = userPost[followeeId];
				while(!tempPost.empty()) {
					tweet temp = tempPost.front();
					allNewsFeed.push_back(temp);
					tempPost.pop();
				}
			}
			else {
				continue;
			}
		}
		sort(allNewsFeed.begin(), allNewsFeed.end());
		while( i < static_cast<int>(allNewsFeed.size()) && feedSize> 0) {
			result.push_back(allNewsFeed[i].id);
			i++;
			feedSize--;
		}
		return result;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
		if(userRelation.find(followerId) == userRelation.end()) {
			set<int> followeeList;
			followeeList.emplace(followerId);
			followeeList.emplace(followeeId);
			userRelation.emplace(followerId, followeeList);
		}
		else {
			userRelation[followerId].emplace(followeeId);
		}
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
		if(userRelation.find(followerId) != userRelation.end()) {
			if(followerId != followeeId) {
				userRelation[followerId].erase(followeeId);
			}			
		}
    }
};
