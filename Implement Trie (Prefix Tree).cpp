class Trie {
private:
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;

        TrieNode() {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
            isEnd = false;
        }
    };

    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) return false;
            node = node->children[index];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (!node->children[index]) return false;
            node = node->children[index];
        }
        return true;
    }
};
