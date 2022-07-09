class Solution:
    def intersection(self, nums: List[List[int]]) -> List[int]:
        s = [0]*1000
        for l in nums:
            for i in l:
                s[i-1] += 1
        res = []
        for i, freq in enumerate(s):
            if freq == len(nums):
                res.append(i+1)
        return res
