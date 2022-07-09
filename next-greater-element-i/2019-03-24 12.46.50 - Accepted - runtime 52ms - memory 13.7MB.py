import queue
import collections

class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        ngeMap = {}
        n = len(nums2)
        self.incq = collections.deque()
        for i in range(n):
            x = nums2[n - 1 - i]
            nge = self.update(x)
            ngeMap[x] = nge
        return [ngeMap[x] for x in nums1]
    
    def update(self, x):
        for i in range(len(self.incq)):
            y = self.incq.popleft()
            if y > x:
                self.incq.appendleft(y)
                self.incq.appendleft(x)
                return y
        self.incq.appendleft(x)
        return -1