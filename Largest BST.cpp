class Info {
public:
    int size;      // Size of subtree
    int maxVal;    // Max value in subtree
    int minVal;    // Min value in subtree
    int ans;       // Size of largest BST in subtree
    bool isBST;    // Is current subtree a BST

    Info(int size, int minVal, int maxVal, int ans, bool isBST) {
        this->size = size;
        this->minVal = minVal;
        this->maxVal = maxVal;
        this->ans = ans;
        this->isBST = isBST;
    }
};

class Solution {
public:
    Info largestBSTHelper(Node* root) {
        // Base case: empty node is a BST of size 0
        if (!root) return Info(0, INT_MAX, INT_MIN, 0, true);

        // Recursively get info from left and right subtrees
        Info left = largestBSTHelper(root->left);
        Info right = largestBSTHelper(root->right);

        // Current node info
        Info curr(0, 0, 0, 0, false);
        curr.size = left.size + right.size + 1;

        // Check if the subtree rooted at root is BST
        if (left.isBST && right.isBST && 
            root->data > left.maxVal && root->data < right.minVal) {
            curr.minVal = min(root->data, left.minVal);
            curr.maxVal = max(root->data, right.maxVal);
            curr.ans = curr.size;
            curr.isBST = true;
        } else {
            curr.ans = max(left.ans, right.ans);
            curr.isBST = false;
        }

        return curr;
    }

    int largestBst(Node *root) {
        return largestBSTHelper(root).ans;
    }
};
