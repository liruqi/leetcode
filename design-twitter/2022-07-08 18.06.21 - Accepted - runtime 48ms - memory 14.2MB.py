import heapq

class Twitter:
    
    def __init__(self):
        self.tweets = {} # id -> [tid]
        self.ts = 0
        self.following = {} # id -> set()
        
    def postTweet(self, userId: int, tweetId: int) -> None:
        q = self.tweets.setdefault(userId,deque())
        self.ts += 1
        q.appendleft([-self.ts, tweetId, userId])
        if len(q)>10:
            q.pop()

    def getNewsFeed(self, userId: int) -> List[int]:
        
        pq = []
        idx = {userId: 0}
        
        if userId  in self.following:
            fol = self.following[userId]
            for x in fol:
                idx[x] = 0
        
        for x in idx:
            if x in self.tweets:            
                pq.append(self.tweets[x][0])
                
        res = []
        heapq.heapify(pq)
        while pq and len(res)<10:
            print("heap:",pq)

            top = heapq.heappop(pq)
            res.append(top[1])
            x = top[2]
            idx[x] += 1
            if idx[x] < len(self.tweets[x]):
                heapq.heappush(pq,self.tweets[x][idx[x]])
                
        return res

    def follow(self, followerId: int, followeeId: int) -> None:
        f = self.following.setdefault(followerId,set())
        f.add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        f = self.following.setdefault(followerId,set())
        f.discard(followeeId)


# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)