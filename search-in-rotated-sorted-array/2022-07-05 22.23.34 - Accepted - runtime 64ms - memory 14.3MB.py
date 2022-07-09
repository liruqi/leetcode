class Solution:
    def search(self, num: List[int], target: int) -> int:
        start=0
        end=len(num)-1
        if num[0] == target:
            return 0
        searchPrefix = target > num[0]
        while(start < end):   
            mid = int((start+end)/2)
            if num[mid]==target:
                return mid
            
            if searchPrefix:
                if num[mid]<num[0]:
                    end=mid-1
                    continue
                if num[mid]<target:
                    start = mid + 1
                    continue
                end = mid - 1
            else:
                if num[mid] >= num[0]:
                    start = mid+1
                    continue
                if num[mid]<target:
                    start = mid + 1
                    continue
                end = mid - 1
                
        return start if num[start]==target else -1