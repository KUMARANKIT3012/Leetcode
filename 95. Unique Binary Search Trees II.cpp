class Solution {
public:
    vector<TreeNode*> solve(int start, int end) {
        vector<TreeNode*> result;

        if (start > end) {
            result.push_back(nullptr);
            return result;
        }
        for (int root = start; root <= end; root++) {
            vector<TreeNode*> leftTrees = solve(start, root - 1);
            vector<TreeNode*> rightTrees = solve(root + 1, end);

            for (TreeNode* left : leftTrees) {
                for (TreeNode* right : rightTrees) {
                    TreeNode* node = new TreeNode(root);
                    node->left = left;
                    node->right = right;
                    result.push_back(node);
                }
            }
        }
        return result;
    }

    vector<TreeNode*> generateTrees(int n) {
        return solve(1, n);
    }
};
