import heapq
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        
        mnums = [-x for x in nums]
        k = k-1
        heapq.heapify(mnums)
        while k>0:                    
            heapq.heappop(mnums)
            #print (mnums)
            k-=1
        return -mnums[0]