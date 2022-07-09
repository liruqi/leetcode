import heapq
class MedianFinder:

    def __init__(self):
        self.smlH=[]
        self.bigH=[]

    def addNum(self, num: int) -> None:
        bigH=self.bigH
        smlH=self.smlH
        
        if bigH and bigH[0]<=num:
            heapq.heappush(bigH, num)
            if len(bigH)-len(smlH)>1:
                heapq.heappush(smlH, 0 - heapq.heappop(bigH))
        else:
            heapq.heappush(smlH, -num)
            if len(smlH)-len(bigH)>1:
                heapq.heappush(bigH, 0 - heapq.heappop(smlH))
                #print("*",bigH,smlH)

    def findMedian(self) -> float:
        bigH=self.bigH
        smlH=self.smlH
        #print(bigH,smlH)
        if len(bigH)==len(smlH):
            return (bigH[0] - smlH[0])/2
        if len(bigH)>len(smlH):
            return bigH[0]
        return -smlH[0]

# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()