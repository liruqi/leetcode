
#define ALPHABETS 26

using namespace std;

class TrieNode
{
public:
    TrieNode * parent;
    TrieNode * children[ALPHABETS];
    vector<int> occurrences;
};

class Trie
{
public:
    TrieNode * root;
    
    Trie() {
        root = (TrieNode *) calloc(1, sizeof(TrieNode));
    }
    
    TrieNode * insert(char* text, int occurrence)
    {
        TrieNode * temp = root;
        
        while (*text) {
            int idx = *text - 'a';
            if (temp->children[idx] == NULL) {
                temp->children[idx] =
                (TrieNode *) calloc(1, sizeof(TrieNode));
                temp->children[idx]->parent = temp; // Assigning parent
            }
            
            temp = temp->children[idx];
        }
        temp->occurrences.push_back(occurrence);      //Mark the occurrence of the word
        return temp;
    }
    
    TrieNode * insert(string text, int occurrence)
    {
        // Converting the input word 'text'
        // into a vector for easy processing
        TrieNode * temp = root;
        
        for (char ch : text) {
            int idx = ch - 'a';
            if (temp->children[idx] == NULL) {
                // There is no node in 'trie_tree' corresponding to this alphabet
                
                // Allocate using calloc(), so that components are initialised
                temp->children[idx] =
                (TrieNode *) calloc(1, sizeof(TrieNode));
                temp->children[idx]->parent = temp; // Assigning parent
            }
            
            temp = temp->children[idx];
        }
        temp->occurrences.push_back(occurrence);      //Mark the occurrence of the word
        return temp;
    }
    
    // Prints the 'trie_tree' in a Pre-Order or a DFS manner
    // which automatically results in a Lexicographical Order
    void lexicographPrint(TrieNode * trie_tree, vector<char> printUtilVector)
    {
        int i;
        bool noChild = true;
        
        vector<int>::iterator itr = trie_tree->occurrences.begin();
        
        for (i = 0; i < ALPHABETS; ++i) {
            if (trie_tree->children[i] == NULL) {
                continue;
            } else {
                noChild = false;
                printUtilVector.push_back('a' + i);    // Select a child
                
                // and explore everything associated with the cild
                lexicographPrint(trie_tree->children[i], printUtilVector);
                printUtilVector.pop_back();
                // Remove the alphabet as we dealt
                // everything associated with it
            }
        }
        
        if (trie_tree->occurrences.size() != 0) {
            // Condition trie_tree->occurrences.size() != 0,
            // is a neccessary and sufficient condition to
            // tell if a node is associated with a word or not
            
            vector<char>::iterator itr = printUtilVector.begin();
            
            while (itr != printUtilVector.end()) {
                printf("%c", *itr);
                ++itr;
            }
            printf(" -> @ index -> ");
            
            vector<int>::iterator counter = trie_tree->occurrences.begin();
            // This is to print the occurences of the word
            
            while (counter != trie_tree->occurrences.end()) {
                printf("%d, ", *counter);
                ++counter;
            }
            
            printf("\n");
        }
        
        printUtilVector.pop_back();
    }
    
    // Searches for the occurence of a word in 'trie_tree',
    // if not found, returns NULL,
    // if found, returns poniter pointing to the
    // last node of the word in the 'trie_tree'
    TrieNode * searchWord(char * text)
    {
        // Functions very similar to insert() function
        TrieNode * temp = root;
        
        while (* text) {
            int idx = *text - 'a';
            if (temp->children[idx]) {
                temp = temp->children[idx];
            } else {
                return NULL;
            }
        }
        return (* text) ? NULL : temp;
    }
    
    // Searches the word first, if not found, does nothing
    // if found, deletes the nodes corresponding to the word
    void removeWord(char * word)
    {
        TrieNode * temp = searchWord(word);
        
        if (temp == NULL) {
            // Word not found
            return;
        }
        
        temp->occurrences.pop_back();    // Deleting the occurence
        
        // 'noChild' indicates if the node is a leaf node
        
        int childCount = 0;
        // 'childCount' has the number of children the current node
        // has which actually tells us if the node is associated with
        // another word .This will happen if 'childCount' >= 2.
        int i;
        
        // Checking children of current node
        for (i = 0; i < ALPHABETS; ++i) {
            if (temp->children[i] != NULL) {
                ++childCount;
            }
        }
        
        if (childCount > 0) {
            // The node has children, which means that the word whose
            // occurrence was just removed is a Suffix-Word
            // So no more nodes have to be deleted
            return;
        }
        
        // todo: free memory,
        // reserve allocated memory for further use.
    }
};


class Solution {
public:
    vector<int> cnt;
    int charcnt[ALPHABETS];
    int wordslen;
    vector<int> findSubstring(string s, vector<string>& words) {
        Trie trie;
        int id = 0;
        cnt.clear();
        wordslen = 0;
        fill(charcnt, charcnt+ALPHABETS, 0);
        for (string w : words) {
            TrieNode *nd = trie.insert(w, id);
            id ++;
            cnt.push_back(0);
            cnt[nd->occurrences[0]] += 1;
            for (char ch : w) {
                wordslen += 1;
                charcnt[ch - 'a'] += 1;
            }
        }
        cout << s.size() << endl;
        vector<int> res;
        int subcnt[ALPHABETS];
        fill(subcnt, subcnt+ALPHABETS, 0);
        for (int i=0; i<wordslen; i++) {
            subcnt[s[i] - 'a'] += 1;
        }
        set<string> bad;
        
        for (int i=0; i+wordslen <=s.size(); i++) {
            if (memcmp(subcnt, charcnt, sizeof(charcnt)) == 0) {
                vector<int> rcnt = cnt;
                string can = s.substr(i, wordslen);
                if (bad.find(can) != bad.end()) {
                    continue;
                }
                if (findMatch(can, trie, rcnt)) {
                    res.push_back(i);
                } else {
                    bad.insert(s.substr(i, wordslen));
                }
            }
            subcnt[s[i] - 'a'] -= 1;
            if (i + wordslen >= s.size()) {
                break;
            }
            subcnt[s[i + wordslen] - 'a'] += 1;
        }
        return res;
    }
    
    bool findMatch(string s, Trie trie, vector<int> & rcnt) {
        TrieNode *it = trie.root;
        for (int i=0; i<s.size(); i++) {
            char ch = s[i];
            it = it->children[ch - 'a'];
            if (! it) {
                return false;
            }
            if (it->occurrences.size() == 0) {
                continue;
            }
            int wordIndex = it->occurrences[0];
            if (rcnt[wordIndex] > 0) {
                rcnt[wordIndex] -= 1;
                if (findMatch(s.substr(i + 1), trie, rcnt)) {
                    return true;
                }
                rcnt[wordIndex] += 1;
            }
        }
        return (accumulate(rcnt.begin(), rcnt.end(), 0) == 0);
    }

};