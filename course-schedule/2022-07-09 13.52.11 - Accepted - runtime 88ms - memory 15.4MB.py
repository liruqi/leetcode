
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        cnt = collections.Counter()

        graph = {}
        for p in prerequisites:
            cp = graph.setdefault(p[1],set())
            graph[p[1]].add(p[0])
            cnt[p[0]] += 1

        # [0,1]
        # 
        q = deque()
        start = 0
        
        for x in range(numCourses):
            if x not in cnt:
                q.append(x)
        while q:
            #print(q, cnt)
            x = q.popleft()
            if x not in graph:
                
                continue
            for i in graph[x]:

                if cnt[i] == 1:
                    cnt.pop(i)
                    q.append(i)
                    continue
                cnt[i] -= 1
        #print(q, cnt.total())

        return cnt.total()==0
        