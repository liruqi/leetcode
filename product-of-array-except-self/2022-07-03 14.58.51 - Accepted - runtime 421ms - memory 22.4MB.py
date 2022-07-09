class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        nlen = len(nums)
        p = 1
        
        fwd = []
        bkw = []
        for x in nums:
            p=p*x
            fwd.append(p)

        nums.reverse()
        p = 1
        for x in nums:
            p=p*x
            bkw.append(p)

        bkw.reverse()
        nums.reverse()
        res = []
        for i in range(nlen):
            x = 1
            if i>0:
                x *= fwd[i-1]
            if i<nlen-1:
                x *= bkw[i+1]
            res.append(x)
        return res