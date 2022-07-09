from collections import Counter
import heapq


class CountedSortedList:
    
    def __init__(self):
        self.sd = SortedDict()
        self.n = 0
        
    def add(self,x):
        self.n+=1
        if x in self.sd:
            self.sd[x]+=1
        else:
            self.sd[x]=1
    def pop(self,index=- 1):
        v = self.sd.peekitem(index)
        return self.remove(v[0])
    
    def __getitem__(self, index):
        return self.sd.peekitem(index)[0]
    
    def remove(self, x):
        #print (self.sd, x)
        y=self.sd[x]
        self.n -= 1
        if y==1:
            self.sd.pop(x)
        else:
            self.sd[x] = y - 1
        return x
    def __len__(self):
        #print (self.n,'->',self.sd)
        return self.n
    

class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        cnt = Counter(tasks)

        q = deque()
        nums = [-cnt[x] for x in cnt]
        heapq.heapify(nums)
        res = 0
        batch = 0
        
        while nums:
            batch = heapq.nsmallest(n+1,nums)
            nb = []
            #print(nums)
            for x in batch:
                heapq.heappop(nums)
                y=x+1
                if y<0:
                    nb.append(y)
            for x in nb:
                heapq.heappush(nums,x)
            
            if len(batch)>=n+1:
                res += len(batch)
            elif nums:
                res += (n+1)
            else:
                res +=  len(batch)
            
        
        return res
    

# ["A","A","A","A","A","A","B","C","D","E","F","G"]
# 2
# deque([[7, 1], [1, 5]])
# 7 + 5*2 - 1