class Solution {
public:
    int dfs(TreeNode* node, int mx) {
        if(!node) return 0;
        int res = node->val >= mx ? 1 : 0;
        mx = max(mx, node->val);
        res += dfs(node->left, mx);
        res += dfs(node->right, mx);
        return res;
    }

    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};
