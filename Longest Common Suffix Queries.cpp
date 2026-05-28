class Solution {
public:
    struct TrieNode {
        int child[26];
        int idx;
        int len;

        TrieNode() {
            memset(child, -1, sizeof(child));
            idx = -1;
            len = INT_MAX;
        }
    };

    vector<TrieNode> trie;

    void updateNode(int node, int wordLen, int index) {
        if(wordLen < trie[node].len || 
          (wordLen == trie[node].len && index < trie[node].idx)) {
            trie[node].len = wordLen;
            trie[node].idx = index;
        }
    }

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        trie.push_back(TrieNode());

        for(int i = 0; i < wordsContainer.size(); i++) {
            string &word = wordsContainer[i];
            int n = word.size();

            int node = 0;
            updateNode(node, n, i);

            for(int j = n - 1; j >= 0; j--) {
                int c = word[j] - 'a';

                if(trie[node].child[c] == -1) {
                    trie[node].child[c] = trie.size();
                    trie.push_back(TrieNode());
                }

                node = trie[node].child[c];
                updateNode(node, n, i);
            }
        }

        vector<int> ans;

        for(string &q : wordsQuery) {
            int node = 0;

            for(int i = q.size() - 1; i >= 0; i--) {
                int c = q[i] - 'a';

                if(trie[node].child[c] == -1) {
                    break;
                }

                node = trie[node].child[c];
            }

            ans.push_back(trie[node].idx);
        }

        return ans;
    }
};
