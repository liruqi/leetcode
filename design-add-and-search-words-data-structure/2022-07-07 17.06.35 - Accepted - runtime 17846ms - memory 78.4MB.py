
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
    
class WordDictionary:

    def __init__(self):
        self.trie = Trie()

    def addWord(self, word: str) -> None:
        self.trie.insert(word)

    def search(self, word: str) -> bool:
        return self.trie.search(word)


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)