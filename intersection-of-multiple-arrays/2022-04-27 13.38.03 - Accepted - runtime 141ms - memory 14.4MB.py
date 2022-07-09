class Solution:
    def intersection(self, nums: List[List[int]]) -> List[int]:
        if len(nums) <= 0:
            return []
        intset = set(nums[0])
        for i in range(1, len(nums)):
            iset = set(nums[i])
            intset = intset.intersection(iset)
        return sorted(intset)
                