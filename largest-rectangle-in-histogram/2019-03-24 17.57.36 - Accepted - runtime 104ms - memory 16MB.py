class Solution:
    
    def largestRectangleArea(self, heights) -> int:
        N = len(heights)
        lIdx, incStack = self.buildIncIndex(heights)
        lIdx = [-1 if x>=N else x for x in lIdx]
        heights.reverse()
        rrIdx, decStack = self.buildIncIndex(heights)

        rrIdx.reverse()
        rIdx = [N - 1 - x if x>=0 else x for x in rrIdx]
        heights.reverse()
        can = 0
        for i in range(N):
            x = heights[i]
            width = 1
            if (lIdx[i] >= 0):
                width += (i - lIdx[i])
            if (rIdx[i] > i):
                width += (rIdx[i] - i)
            can = max(can, width * x)
        return can

    def buildIncIndex(self, heights):
        leftIdx, incStack = [], []
        N = len(heights)

        for i in range(len(heights)):
            x = heights[i]
            idx = N
            while incStack and x <= heights[incStack[-1]]:
                idx = incStack[-1]
                incStack.pop()
            if (idx < N and leftIdx[idx]<N):
                idx = leftIdx[idx]
            incStack.append(i)
            leftIdx.append(idx)
        return (leftIdx, incStack)