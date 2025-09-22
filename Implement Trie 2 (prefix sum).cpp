#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    int cntEnd;    // how many words end at this node
    int cntPrefix; // how many words pass through this node

    TrieNode() {
        cntEnd = 0;
        cntPrefix = 0;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the Trie
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (node->children[idx] == nullptr) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
            node->cntPrefix++;
        }
        node->cntEnd++;
    }

    // Count words equal to word
    int countWordsEqualTo(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (node->children[idx] == nullptr) return 0;
            node = node->children[idx];
        }
        return node->cntEnd;
    }

    // Count words starting with prefix
    int countWordsStartingWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (node->children[idx] == nullptr) return 0;
            node = node->children[idx];
        }
        return node->cntPrefix;
    }

    // Erase one occurrence of word
    void erase(string word) {
        if (countWordsEqualTo(word) == 0) return; // word not present

        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            TrieNode* next = node->children[idx];
            next->cntPrefix--;
            node = next;
        }
        node->cntEnd--;
    }
};

// Example usage
int main() {
    Trie* obj = new Trie();
    obj->insert("apple");
    obj->insert("apple");
    obj->insert("app");

    cout << obj->countWordsEqualTo("apple") << endl;      // 2
    cout << obj->countWordsStartingWith("app") << endl;   // 3

    obj->erase("apple");
    cout << obj->countWordsEqualTo("apple") << endl;      // 1
    cout << obj->countWordsStartingWith("app") << endl;   // 2

    return 0;
}
