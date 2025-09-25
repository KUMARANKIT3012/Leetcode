class Solution {
    struct Node {
        Node* links[2]; // 0 and 1

        bool contains(int bit) {
            return links[bit] != nullptr;
        }

        Node* get(int bit) {
            return links[bit];
        }

        void put(int bit, Node* node) {
            links[bit] = node;
        }
    };

    Node* root;

    void insert(int num) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->contains(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getMax(int num) {
        Node* node = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->contains(1 - bit)) {
                maxNum |= (1 << i);
                node = node->get(1 - bit);
            } else {
                node = node->get(bit);
            }
        }
        return maxNum;
    }

public:
    int findMaximumXOR(vector<int>& nums) {
        root = new Node();

        // Insert all numbers
        for (int num : nums) {
            insert(num);
        }

        int maxXor = 0;
        for (int num : nums) {
            maxXor = max(maxXor, getMax(num));
        }
        return maxXor;
    }
};
