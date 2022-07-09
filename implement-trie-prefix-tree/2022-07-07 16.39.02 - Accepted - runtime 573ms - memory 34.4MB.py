ORDA=ord('a')

class TrieNode:
    def __init__(self):
        self.children = [None]*26
        self.cnt = 0
        self.word = 0
        
    def insert(self, w):
        if not w:
            self.word += 1
            return
        
        idx = ord(w[0])-ORDA
        if self.children[idx]==None:
            self.cnt += 1
            self.children[idx] = TrieNode()
        self.children[idx].insert(w[1:])
        
    def find(self, w):
        if not w:
            return self
        idx = ord(w[0])-ORDA
        if self.children[idx]==None:
            return None
        return self.children[idx].find(w[1:])
    
class Trie:

    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        self.root.insert(word)

    def search(self, word: str) -> bool:
        tn = self.root.find(word)
        return tn and tn.word >= 1

    def startsWith(self, prefix: str) -> bool:
        tn = self.root.find(prefix)
        return tn and tn.cnt+tn.word >= 1


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)