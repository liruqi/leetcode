from collections import Counter

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        cnts = {}
        idxs = []
        strsIdx = 0
        for x in strs:
            #counter = tuple(sorted(Counter(x).items()))
            counter = ''.join(sorted(x))
            foundAna = counter in cnts
            
            if foundAna:
                #print (x, cnts[counter], len(cnts))
                idxs[cnts[counter]].append(x)
            else:
                cnts[counter] = len(idxs)
                idxs.append([x])
            strsIdx += 1
        return idxs