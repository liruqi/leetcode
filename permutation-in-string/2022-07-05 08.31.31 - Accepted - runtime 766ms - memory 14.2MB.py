from collections import Counter

class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        s1len = len(s1)
        if s1len > len(s2):
            return False
        s1cnter = Counter(s1)
        s1t = tuple(sorted(s1cnter.items()))
        s2cnter = Counter(s2[:len(s1)])
        if s1t == tuple(sorted(s2cnter.items())):
            return True
        print (s1t)
        for i in range(len(s2)-s1len):
            s2cnter[s2[i]] -= 1
            if s2cnter[s2[i]] == 0:
                del s2cnter[s2[i]]
            s2cnter[s2[i + s1len]] += 1
            print(i, "->", tuple(sorted(s2cnter.items())))
            if s1t == tuple(sorted(s2cnter.items())):
                return True
        return False