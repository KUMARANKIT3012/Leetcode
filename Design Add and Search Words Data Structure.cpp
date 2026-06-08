class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool word = false;
};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for(char c : word) {
            if(cur->children.find(c) == cur->children.end())
                cur->children[c] = new TrieNode();
            cur = cur->children[c];
        }
        cur->word = true;
    }
    
    bool dfs(int j, TrieNode* root, string &word) {
        TrieNode* cur = root;
        for(int i = j; i < word.size(); i++) {
            char c = word[i];
            if(c == '.') {
                for(auto child : cur->children) {
                    if(dfs(i + 1, child.second, word))
                        return true;
                }
                return false;
            } else {
                if(cur->children.find(c) == cur->children.end())
                    return false;
                cur = cur->children[c];
            }
        }
        return cur->word;
    }

    bool search(string word) {
        return dfs(0, root, word);
    }
};
