from sortedcontainers import SortedDict
import heapq
class KthLargest:
    
    def __init__(self, k: int, nums: List[int]):
        self.topkm1 = nums[:k-1] #min
        self.small = []
        self.K=k
        heapq.heapify(self.topkm1)
        
        for x in nums[k-1:]:
            y = heapq.heappushpop(self.topkm1,x)
            heapq.heappush(self.small,-y)
    def add(self, val: int) -> int:
        if (len(self.topkm1) == self.K):
            kp1 = heapq.heappushpop(self.topkm1,val)
            return self.topkm1[0]
        heapq.heappush(self.topkm1, val)
        #print(self.topkm1, self.small)
        if self.small:
            heapq.heappushpop(self.topkm1, -self.small[0])
        
        return self.topkm1[0]

# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)