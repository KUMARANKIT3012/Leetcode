class Solution {
public:
    void dfs(TreeNode* node, int level, vector<int>& view) {
        if (node == NULL) return;

        // view mera DS hai jo ans store karega
        // If this is the first node we visit at this level, add it to view
        if (level == view.size()) {
            view.push_back(node->val);
        }

        // Go right first to ensure rightmost node is visited first at each level
        dfs(node->right, level + 1, view);
        dfs(node->left, level + 1, view);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> view;
        dfs(root, 0, view);
        return view;
    }
};




// BFS : 
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int qLen = q.size();
            TreeNode* rightSide = nullptr;

            for (int i = 0; i < qLen; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node) {
                    rightSide = node;

                    if (node->left) {
                        q.push(node->left);
                    }

                    if (node->right) {
                        q.push(node->right);
                    }
                }
            }

            if (rightSide) {
                res.push_back(rightSide->val);
            }
        }

        return res;
    }
};
