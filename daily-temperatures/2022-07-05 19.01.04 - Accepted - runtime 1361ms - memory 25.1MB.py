class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        ans = []
        n = len(temperatures)
        days = 0
        stk = []
        for x in range(n):
            i = n - x - 1
            if not ans:
                ans.append(days)
                stk.append((i, temperatures[i]))
                continue
            
            while stk and temperatures[i] >= stk[-1][1]:
                stk.pop()
            #print(i, stk)
            ans.append(stk[-1][0] - i if stk else 0)
            stk.append((i, temperatures[i]))
        ans.reverse()
        return ans
            