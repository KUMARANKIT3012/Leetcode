class Node {
public:
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }

    bool checkIfPrefixExists(string word) {
        Node* node = root;
        for (char ch : word) {
            if (node->containsKey(ch)) {
                node = node->get(ch);
                if (node->isEnd() == false) {
                    return false;
                }
            } else {
                return false;
            }
        }
        return true;
    }
};

class Solution {
  public:
    string longestString(vector<string> &words) {
        Trie trie;
        for (auto &word : words) {
            trie.insert(word);
        }

        string ans = "";
        for (auto &word : words) {
            if (trie.checkIfPrefixExists(word)) {
                if (word.size() > ans.size() || (word.size() == ans.size() && word < ans)) {
                    ans = word;
                }
            }
        }
        return ans;
    }
};
