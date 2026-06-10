class Solution {
public:
    int curSum = 0;
    void dfs(TreeNode* node) {
        if (!node) {
            return;
        }
        dfs(node->right);
        int temp = node->val;
        node->val += curSum;
        curSum += temp;
        dfs(node->left);
    }

    TreeNode* convertBST(TreeNode* root) {
        dfs(root);
        return root;
    }
};
