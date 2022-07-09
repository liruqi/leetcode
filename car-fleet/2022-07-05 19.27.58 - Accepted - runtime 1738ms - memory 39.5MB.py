class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        n = len(position)
        stk = []
        for i in range(n):
            stk.append((target - position[i], speed[i]))
        stk.sort(key=lambda x: -x[0])
        #print(stk)
        ans = 0
        while stk:
            #i = n - x - 1
            top = stk.pop()
            dist = top[0]
            #print (dist, top[1], '->', top[1]/dist)
            while stk and dist * stk[-1][1]  >= stk[-1][0] * top[1] :
                #print (stk[-1], stk[-1][0]/stk[-1][1])
                stk.pop()
                
            ans += 1
        return ans