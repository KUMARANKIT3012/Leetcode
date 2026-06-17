class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool found = false;
        for (auto &word : wordList) {
            if (word == endWord) {
                found = true;
                break;
            }
        }
        if (!found) return 0;
        unordered_map<string, vector<string>> nei;
        wordList.push_back(beginWord);
        for (auto &word : wordList) {
            for (int i = 0; i < word.size(); i++) {
                string pattern = word;
                pattern[i] = '*';
                nei[pattern].push_back(word);
            }
        }
        queue<string> q;
        unordered_set<string> visit;
        q.push(beginWord);
        visit.insert(beginWord);
        int res = 1;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                string word = q.front();
                q.pop();
                if (word == endWord) return res;
                for (int i = 0; i < word.size(); i++) {
                    string pattern = word;
                    pattern[i] = '*';
                    for (auto &neiWord : nei[pattern]) {
                        if (!visit.count(neiWord)) {
                            visit.insert(neiWord);
                            q.push(neiWord);
                        }
                    }
                }
            }
            res++;
        }
        return 0;
    }
};
