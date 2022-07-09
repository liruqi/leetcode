from collections import Counter
class TrieNode:
    def __init__(self):
        self.children = {}
        self.word = 0
        
    def insert(self, w):
        current = self
        for ch in w:
            if ch not in current.children:
                #print("insert",w,ch)
                current.children[ch] = TrieNode()
            current = current.children[ch]
        current.word += 1
        
    def find(self, w):
        if not w:
            return self
        
        if w[0] not in self.children:
            #print(w, None)
                
            return None
        return self.children[w[0]].find(w[1:])
    
    def match(self, w):
        if not w:
            return self.word > 0
        
        if w[0] not in self.children:
            #print(w, None)
            if w[0]=='.':
                for x in self.children:
                    if self.children[x].match(w[1:]):
                        return True
                    
            return False
        return self.children[w[0]].match(w[1:])
    
class Solution:
    n = 0
    moves = [
        [1,0],
        [-1,0],
        [0,1],
        [0,-1]
    ]
    def dfs(self, r, c, node):
        p = tuple((r,c))
        if p in self.visited:
            return False

        ch = self.b[r][c]

        if ch in node.children:
            if node.children[ch].word > 0:
                node.children[ch].word = 0
                return True
        else :
            return False
        self.visited.add(p)
        for move in self.moves:
            rr = r+move[0]
            cc = c+move[1]
            if rr<0 or rr>=self.m:
                continue
            if cc<0 or cc>=self.n:
                continue
            
            if ch in node.children:
                
                sf = self.dfs(rr,cc,node.children[ch])
                if sf:
                    return True
        self.visited.remove(p)
        return False
    
    def exist(self, board: List[List[str]], word: str) -> bool:
        self.root = TrieNode()
        self.root.insert(word)
        self.b = board
        self.m = len(board)
        wordCnt = Counter(word)
        
        boardCnt = Counter()
        for r in board:
            for c in r:
                boardCnt[c]+=1
        for x in wordCnt:
            if wordCnt[x]>boardCnt[x]:
                return False
            
        for i in range(self.m):
            row = board[i]
            self.n = len(row)
            for j in range(self.n):
                self.visited = set()
                s = self.dfs(i, j, self.root)
                if s:
                    return True
            
        return False