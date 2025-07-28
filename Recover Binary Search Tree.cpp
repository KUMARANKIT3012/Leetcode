class Solution {
private:
    TreeNode* first = NULL;
    TreeNode* middle = NULL;
    TreeNode* last = NULL;
    TreeNode* prev = new TreeNode(INT_MIN);

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        if (prev && root->val < prev->val) {
            // First violation
            if (!first) {
                first = prev;
                middle = root;
            } else {
                // Second violation
                last = root;
            }
        }
        prev = root;

        inorder(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        inorder(root);

        // Case 1: swapped nodes are not adjacent (e.g., 1 and 4 swapped)
        if (first && last)
            swap(first->val, last->val);
        // Case 2: swapped nodes are adjacent (e.g., 3 and 2 swapped)
        else if (first && middle)
            swap(first->val, middle->val);
    }
};
