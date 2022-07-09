class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        mtx = []
        for row in matrix:
            c = 0
            drow = []
            for x in row:
                if x == "0":
                    c = 0
                    drow.append(0)
                else:
                    c+=1
                    drow.append(c)
            mtx.append(drow)
        can = 0
        for i in range(len(mtx)):
            row = mtx[i]
            for j in range(len(row)):
                k = i
                area = 0
                minr = row[j]
                while (minr > 0):
                    can = max(can,
                              minr * (1 + i - k))
                    k -= 1
                    if (k < 0):
                        break
                    minr = min(minr, mtx[k][j])
        return can
        