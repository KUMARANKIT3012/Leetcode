class Solution {
public:
    TreeNode* dfs(TreeNode* root) {
        if (!root) {
            return NULL;
        }
        TreeNode* leftTail = dfs(root->left);
        TreeNode* rightTail = dfs(root->right);
        if (root->left) {
            leftTail->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }

        TreeNode* last;

        if (rightTail) {
            last = rightTail;
        } else if (leftTail) {
            last = leftTail;
        } else {
            last = root;
        }

        return last;
    }

    void flatten(TreeNode* root) {
        dfs(root);
    }
};
