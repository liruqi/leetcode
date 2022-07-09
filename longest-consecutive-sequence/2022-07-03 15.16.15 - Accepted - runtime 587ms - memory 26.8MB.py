class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        ss = sorted(nums)
        res = 1
        slen = 1
        if len(ss) == 0:
            return 0
        
        val = ss[0]
        for i in range(1, len(ss)):
            if ss[i]==val+1:
                slen += 1
                res = max(res, slen)
            elif ss[i]>val+1:
                slen = 1
            val = ss[i]
        return res