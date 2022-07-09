class Solution:
    
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        ds = [-1]*(len(edges)+1)

        def getRoot(x):
            while x >=0 and ds[x] != x:
                x = ds[x]
            return x
        
        graph = {}
        
        for p in edges:
            r0 = getRoot(p[0])
            r1 = getRoot(p[1])
            
            if r0 < r1:
                r0,r1 = r1,r0
                p[0],p[1]=p[1],p[0]
            #print (ds, p, r0, r1)
            if r0 >= 0:
                if r1==r0:
                    return p
                if r1<0:
                    ds[p[1]]=r0
                    continue
                ds[r1]=r0
                continue

            ds[p[0]]=p[0]
            ds[p[1]]=p[0]
        return []
                
                
        
        