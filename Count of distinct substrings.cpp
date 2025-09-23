/*You are required to complete this method */
struct Node {
    Node* links[26];

    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }
};

int countDistinctSubstring(string s) {
    Node* root = new Node();
    int count = 0;

    for (int i = 0; i < s.size(); i++) {
        Node* node = root;
        for (int j = i; j < s.size(); j++) {
            char ch = s[j];
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
                count++;
            }
            node = node->get(ch);
        }
    }
    return count + 1;  // +1 to include the empty substring
}
