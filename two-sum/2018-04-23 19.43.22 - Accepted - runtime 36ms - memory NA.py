class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        m = {}
        for i in range(len(nums)):
            a = nums[i]
            b = target - a
            if b in m:
                return [m[b], i]
            m[a] = i
            