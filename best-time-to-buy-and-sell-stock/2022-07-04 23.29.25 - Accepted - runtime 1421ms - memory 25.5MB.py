class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        profit = 0
        rinc = []
        i = n - 1
        while i>0:
            if len(rinc)==0:
                rinc.append((i,prices[i]))
            elif prices[i] > rinc[len(rinc)-1][1]:
                rinc.append((i,prices[i]))
            i-=1
            
        i = 0
        while i < n:
            if (len(rinc) == 0):
                break
            profit = max(profit, rinc[len(rinc)-1][1] - prices[i])
            if i>=rinc[len(rinc)-1][0]:
                rinc.pop()
            i += 1
        return profit