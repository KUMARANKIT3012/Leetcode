class TrieNode {
public:
    TrieNode* children[26];
    bool isWord;
    string word;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }

        isWord = false;
    }
};

class Solution {
public:
    void addWord(TrieNode* root, string& word) {
        TrieNode* cur = root;

        for (char c : word) {
            int idx = c - 'a';

            if (cur->children[idx] == nullptr) {
                cur->children[idx] = new TrieNode();
            }

            cur = cur->children[idx];
        }

        cur->isWord = true;
        cur->word = word;
    }

    void dfs(vector<vector<char>>& board, int r, int c,
             TrieNode* node, vector<string>& res) {

        char ch = board[r][c];

        if (ch == '#' || node->children[ch - 'a'] == nullptr) {
            return;
        }

        node = node->children[ch - 'a'];

        if (node->isWord) {
            res.push_back(node->word);
            node->isWord = false;
        }

        board[r][c] = '#';

        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        for (auto& d : dirs) {
            int nr = r + d[0];
            int nc = c + d[1];

            if (nr >= 0 && nc >= 0 &&
                nr < board.size() &&
                nc < board[0].size()) {
                dfs(board, nr, nc, node, res);
            }
        }

        board[r][c] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();

        for (string& word : words) {
            addWord(root, word);
        }

        vector<string> res;

        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[0].size(); c++) {
                dfs(board, r, c, root, res);
            }
        }

        return res;
    }
};
