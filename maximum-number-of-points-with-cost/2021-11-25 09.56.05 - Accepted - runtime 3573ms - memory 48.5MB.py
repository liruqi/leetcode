import copy
class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        dp = points
        for i in range(1, len(dp)):
            base = dp[i-1]
            add = base[0]
            adds = []
            n = len(base)
            for j in range(n):
                x = max(base[j], add)
                adds.append(x)
                add = x - 1
            add = base[-1]
            for j in reversed(range(n)):
                x = max(base[j], add)
                adds[j] = max(adds[j], x)
                add = x - 1
            for j in range(n):
                dp[i][j] = points[i][j]+adds[j]
        return max(dp[-1])
    