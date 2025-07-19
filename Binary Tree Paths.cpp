class Solution {
public:
    void helper(TreeNode* root, string path, vector<string>& paths) {
        if (!root) return;

        // Add current node value to the path
        if (!path.empty()) {
            path += "->";
        }
        path += to_string(root->val);

        // If it's a leaf node, add the path to the result
        if (!root->left && !root->right) {
            paths.push_back(path);
            return;
        }

        // Recurse left and right
        helper(root->left, path, paths);
        helper(root->right, path, paths);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        helper(root, "", paths);
        return paths;
    }
};
