class Solution {
public:
    bool dfs(TreeNode* node, int curSum, int targetSum) {
        if (!node) {
            return false;
        }
        curSum += node->val;
        if (!node->left && !node->right) {
            return curSum == targetSum;
        }
        return dfs(node->left, curSum, targetSum) || dfs(node->right, curSum, targetSum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root, 0, targetSum);
    }
};
