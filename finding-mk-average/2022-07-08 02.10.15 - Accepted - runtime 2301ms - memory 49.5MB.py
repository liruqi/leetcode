import heapq
from sortedcontainers import SortedDict,SortedList

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
    
class MKAverage:

    def __init__(self, m: int, k: int):
        self.topK=CountedSortedList()
        self.bottomK=CountedSortedList()
        self.mK = CountedSortedList()

        self.M=m
        self.K=k
        self.q = deque()
        self.qs = None
    
    
    def iniMembers(self):
        self.qs = 0
        for x in self.q:
            self.qs += x
            self.mK.add(x)
            
        for x in range(self.K):
            y = self.mK.pop(0)
            self.qs -= y
            self.bottomK.add(y)
        for x in range(self.K):
            y = self.mK.pop()
            self.qs -= y
            self.topK.add(y)
        print('*', self.q,self.topK.sd,self.bottomK.sd)

    def addElement(self, num: int) -> None:
        self.q.append(num)        
        qlen = len(self.q)
        if qlen < self.M:
            return
        if qlen == self.M:
            self.iniMembers() 
            return 
        
        qLeft = self.q.popleft()
        #print(num, qLeft, '*', self.q,self.topK.sd,self.bottomK.sd)
        if num >= self.topK[0]:
            self.topK.add(num)
        elif num<=self.bottomK[-1]:
            self.bottomK.add(num)
        else:
            self.mK.add(num)
            self.qs += num
            
        if qLeft >= self.topK[0]:
            self.topK.remove(qLeft)
        elif qLeft<=self.bottomK[-1]:
            self.bottomK.remove(qLeft)
        else:
            self.mK.remove(qLeft)
            self.qs -= qLeft
        
        if len(self.topK) < self.K:
            mKrightV = self.mK.pop()
            self.qs -= mKrightV
            self.topK.add(mKrightV)
        elif len(self.topK) > self.K:
            mKrightV = self.topK.pop(0)
            self.qs += mKrightV
            self.mK.add(mKrightV)
        
        if len(self.bottomK) < self.K:
            rightV = self.mK.pop(0)
            self.qs -= rightV
            self.bottomK.add(rightV)
        elif len(self.bottomK) > self.K:
            mKrightV = self.bottomK.pop()
            self.qs += mKrightV
            self.mK.add(mKrightV)
        
            
    def calculateMKAverage(self) -> int:
        if self.qs == None:
            return -1
        print(self.mK, self.qs)
        return (int) (self.qs / (self.M-2*self.K) )


# Your MKAverage object will be instantiated and called as such:
# obj = MKAverage(m, k)
# obj.addElement(num)
# param_2 = obj.calculateMKAverage()