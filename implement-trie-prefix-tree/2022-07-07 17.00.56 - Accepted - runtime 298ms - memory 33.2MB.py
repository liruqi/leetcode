ORDA=ord('a')

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
        return tn and len(tn.children)+tn.word >= 1


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)