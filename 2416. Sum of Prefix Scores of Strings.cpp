class Solution {
public:
    struct Node {
        Node* child[26];
        int count;

        Node() {
            count = 0;
            for (int i = 0; i < 26; i++)
                child[i] = nullptr;
        }
    };

    vector<int> sumPrefixScores(vector<string>& words) {
        Node* root = new Node();

        for (string& word : words) {
            Node* curr = root;

            for (char ch : word) {
                int idx = ch - 'a';

                if (curr->child[idx] == nullptr)
                    curr->child[idx] = new Node();

                curr = curr->child[idx];
                curr->count++;
            }
        }

        vector<int> ans;

        for (string& word : words) {
            Node* curr = root;
            int score = 0;

            for (char ch : word) {
                curr = curr->child[ch - 'a'];
                score += curr->count;
            }

            ans.push_back(score);
        }

        return ans;
    }
};
