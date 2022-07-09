from sortedcontainers import SortedDict

class KthLargest:
    
    def __init__(self, k: int, nums: List[int]):
        self.sd = SortedDict()
        self.K = k
        nums.sort()
        nums.reverse()
        self.cnt = 0
        for x in nums:
            x = -x
            if x in self.sd:
                self.sd[x]+=1
            else:
                self.sd[x] = 1
            self.cnt += 1
            if self.cnt >= k:
                break
    def add(self, val: int) -> int:
        
        val = 0-val
        #print(self.sd,val)

        x = val
        if x in self.sd:
            self.sd[x]+=1
        else:
            self.sd[x] = 1
        if self.cnt < self.K:
            self.cnt += 1
        else:
            last = self.sd.peekitem()
            if last[1] == 1:
                self.sd.pop(last[0])
            else:
                self.sd[last[0]] = last[1]-1
                return -last[0]
        return -self.sd.peekitem()[0]

# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)