from collections import Counter

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        cnts = sorted(Counter(nums).items(), key=itemgetter(1))
        return  [x[0] for x in cnts[-k:]]