class Solution:
    def partition(self, s: str) -> List[List[str]]:
        if not s:
            return [[]]
        if len(s)==1:
            return [[s]]
        i=0
        ans=[]
        while i<len(s):
            i+=1
            prefix = s[:i]
            rp = prefix[::-1]
            if prefix == rp:
                r = self.partition(s[i:])
                ans += [[prefix] + x for x in r]
        return ans