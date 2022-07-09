class Solution:
        
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        cnt = collections.Counter()

        graph = {}
        for p in prerequisites:
            cp = graph.setdefault(p[1],set())
            graph[p[1]].add(p[0])
            cnt[p[0]] += 1

        q = []
        start = 0
        
        for x in range(numCourses):
            if x not in cnt:
                q.append(x)
        while q[start:]:
            #print(q, cnt)
            x = q[start]
            start+=1

            if x not in graph:
                
                continue
            for i in graph[x]:

                if cnt[i] == 1:
                    cnt.pop(i)
                    q.append(i)
                    continue
                cnt[i] -= 1
        #print(q, cnt.total())

        return q if cnt.total()==0 else []
    
        