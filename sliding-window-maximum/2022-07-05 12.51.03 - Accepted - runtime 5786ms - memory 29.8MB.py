from collections import Counter
from sortedcontainers import SortedDict

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        cnt=Counter(nums[:k])
        sd=SortedDict(cnt)
        ret=[sd.peekitem()[0]]
        
        for i in range(k, len(nums)):
            sd[nums[i-k]] -= 1
            if nums[i] in sd:
                sd[nums[i]] += 1
            else:
                sd[nums[i]] = 1
            if sd[nums[i-k]] == 0:
                del sd[nums[i-k]]
            #print (cnt)
            ret.append(sd.peekitem()[0])
        return ret