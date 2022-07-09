class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        cost = [0] + cost + [0]
        dp = [0]
        idx = 1
        for c in cost[1:]:
            mc = dp[idx - 1] + cost[idx - 1]
            if (idx > 1):
                mc = min(mc, dp[idx - 2] + cost[idx - 2])
            dp.append(mc)
            idx += 1
            
        return dp[-1]