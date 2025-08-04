class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        vector<vector<string>> ans;

        if (st.find(endWord) == st.end()) return ans;

        queue<vector<string>> q;
        q.push({beginWord});

        unordered_set<string> usedOnLevel;
        int level = 0;
        vector<string> visitedThisLevel;
        visitedThisLevel.push_back(beginWord);

        while (!q.empty()) {
            vector<string> path = q.front();
            q.pop();

            // Level change → erase words used on previous level
            if (path.size() > level) {
                level++;
                for (auto& w : visitedThisLevel) {
                    st.erase(w);
                }
                visitedThisLevel.clear();
            }

            string word = path.back();

            // Found one valid shortest path
            if (word == endWord) {
                if (ans.empty() || path.size() == ans[0].size()) {
                    ans.push_back(path);
                } else {
                    break; // longer paths can be ignored
                }
            }

            for (int i = 0; i < word.size(); i++) {
                string temp = word;
                for (char c = 'a'; c <= 'z'; c++) {
                    temp[i] = c;
                    if (st.find(temp) != st.end()) {
                        path.push_back(temp);
                        q.push(path);
                        visitedThisLevel.push_back(temp);
                        path.pop_back(); // backtrack
                    }
                }
            }
        }

        return ans;
    }
};
