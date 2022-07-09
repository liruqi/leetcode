
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
    
class Trie:

    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        self.root.insert(word)

    def search(self, word: str) -> bool:
        return self.root.match(word)

    def startsWith(self, prefix: str) -> bool:
        tn = self.root.find(prefix)
        return tn and len(tn.children)+tn.word >= 1
    
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
            return []
        res = []
        ch = self.b[r][c]
        #if node.word > 0:
        #    node.word = 0
        #    res.append("")
        #else:
        if True:
            if ch in node.children:
                if node.children[ch].word > 0:
                    node.children[ch].word = 0
                    res.append(ch)
                    if len(node.children[ch].children) == 0:
                        del node.children[ch]
            else :
                return []
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
                    #print("sf",sf)
                    res = res + [ch + x for x in sf]
        self.visited.remove(p)
        return res
    
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        self.root = TrieNode()
        for w in words:
            self.root.insert(w)
        self.b = board
        self.m = len(board)
        
        res = []
        for i in range(self.m):
            row = board[i]
            self.n = len(row)
            for j in range(self.n):
                self.visited = set()
                s = self.dfs(i, j, self.root)
                if s:
                    res = res + s
            
        return res