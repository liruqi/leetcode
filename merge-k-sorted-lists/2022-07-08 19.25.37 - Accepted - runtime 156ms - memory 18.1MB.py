# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        pt = []
        pq = []
        i=0
        for lst in lists:
            i+=1
            if lst:
                pq.append([lst.val,i,lst])
                
        res = None
        it = None
        heapq.heapify(pq)
        while pq:
            #print("heap:",pq)
            
            top = heapq.heappop(pq)
            
            x = top[2]
            if res==None:
                res = x
                it = x
            else:
                it.next=x
                it=x
                
            if x.next:
                x = x.next
                heapq.heappush(
                    pq,
                    [x.val,top[1],x])
        return res
                