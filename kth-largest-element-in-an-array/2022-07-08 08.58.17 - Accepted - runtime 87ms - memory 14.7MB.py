import heapq
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        ks = len(nums)-k
        heapq.heapify(nums)
        while ks>0:                    
            heapq.heappop(nums)
            ks-=1
        return nums[0]
