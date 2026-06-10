class Solution {
public:
    void preorder(TreeNode* root, string& res) {
        if (!root) {
            return;
        }
        res += to_string(root->val);
        if (root->left || root->right) {
            res += "(";
            preorder(root->left, res);
            res += ")";
        }
        if (root->right) {
            res += "(";
            preorder(root->right, res);
            res += ")";
        }
    }

    string tree2str(TreeNode* root) {
        string res;
        preorder(root, res);
        return res;
    }
};
