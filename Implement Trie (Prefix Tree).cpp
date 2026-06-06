class Trie {
private:
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        bool endOfWord = false;
    };

    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for(char c : word) {
            if(cur->children.find(c) == cur->children.end()) {
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur->endOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for(char c : word) {
            if(cur->children.find(c) == cur->children.end()) {
                return false;
            }
            cur = cur->children[c];
        }
        return cur->endOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for(char c : prefix) {
            if(cur->children.find(c) == cur->children.end()) {
                return false;
            }
            cur = cur->children[c];
        }
        return true;
    }
};
