class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        heights.append(0)
        n = len(heights)
        incStk = []
        res = 0
        for i in range(n):
            res = max(res, heights[i])
            if not incStk:
                incStk.append([i,heights[i]])            
                continue
                
            top = []
            while incStk and incStk[-1][1] >= heights[i]:
                #print ("*", incStk)
                j = -1
                res=max(res, (i-incStk[j][0]) * incStk[j][1])
                #res = max(res, (i+1-incStk[j][0])*min(incStk[j][1],heights[i]))

                top = incStk.pop()
                #print(i,top, '->', res)
            
            incStk.append( [top[0] if top else i,heights[i]])
        return res