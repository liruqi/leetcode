import heapq
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        if k > len(nums)/2:
            ks = len(nums)-k
            heapq.heapify(nums)
            while ks>0:                    
                heapq.heappop(nums)
                ks-=1
            return nums[0]
        
        mnums = [-x for x in nums]
        k = k-1
        heapq.heapify(mnums)
        while k>0:                    
            heapq.heappop(mnums)
            #print (mnums)
            k-=1
        return -mnums[0]