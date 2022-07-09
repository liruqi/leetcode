from collections import Counter
import string

class Solution:
    def ge(self,s1,s2):
        #for x in  string.lowercase+string.uppercase:
        for x in  string.ascii_lowercase+string.ascii_uppercase:
            if s1[ord(x)] < s2[ord(x)]:
                return False
        return True
    
    def minWindow(self, s: str, t: str) -> str:
        s2len = len(t)
        if len(s) < s2len:
            return ""
        
        s1cnter = [0] * 128
        s2cnter = [0] * 128
        for ch in t:
            s2cnter[ord(ch)] += 1
        

        start = 0
        end = s2len
        for ch in s[:s2len]:
            s1cnter[ord(ch)] += 1
        
        if s1cnter == s2cnter:
            return s[:s2len]
        ret = s+t
        included = 0
        while (start < end):
            if included == 1:
                ch = s[start]

                start += 1
                if s2cnter[ord(ch)] > 0:
                    s1cnter[ord(ch)]-=1
                if s1cnter[ord(ch)] >= s2cnter[ord(ch)]:
                    can = s[start:end]
                    if len(can) < len(ret):
                        ret = can
                else:
                    included = 0
                #print(included, start, end)
                continue
                
            if end >= len(s):
                break
            ch = s[end]
            if s2cnter[ord(ch)] == 0:
                end+=1
                #print("L49",included, start, end)
                continue
            
            s1cnter[ord(ch)]+=1
            end += 1
            if s1cnter[ord(ch)] == s2cnter[ord(ch)]:
                s1ge = self.ge(s1cnter, s2cnter)
                if s1ge:
                    included = 1
                    
                    can = s[start:end]
                    if len(can) < len(ret):
                        ret = can
                        print("*", ret)
            #print("L63",included, start, end)
        if ret == s+t:
            return ""
        return ret
            
