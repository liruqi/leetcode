import heapq

class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        w = [-x for x in stones]
        heapq.heapify(w)
        while w:
            s1 = heapq.heappop(w)
            if not w:
                return -s1
            s2 = heapq.heappop(w)
            if s1 == s2:
                continue
            if s1 < s2:
                heapq.heappush(w,s1 - s2)
                continue
            heapq.heappush(w,s2 - s1)
        return 0
