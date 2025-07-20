class Solution {
public:
    // Step 1: Mark parents and find target node
    TreeNode* bfsToMapParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentTrack, int start) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* res = nullptr;

        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();

            if (node->val == start) {
                res = node;
            }

            if (node->left) {
                parentTrack[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                parentTrack[node->right] = node;
                q.push(node->right);
            }
        }
        return res;
    }

    // Step 2: BFS to find all nodes at distance k
    int findMaxDistance(unordered_map<TreeNode*, TreeNode*> &parentTrack, TreeNode* target) {
        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> visited;

        q.push(target);
        visited[target] = true;
        int maxDist = 0;

        while (!q.empty()) {
            int size = q.size();
            bool foundNew = false;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front(); q.pop();

                // Check left child
                if (node->left && !visited[node->left]) {
                    foundNew = true;
                    visited[node->left] = true;
                    q.push(node->left);
                }

                // Check right child
                if (node->right && !visited[node->right]) {
                    foundNew = true;
                    visited[node->right] = true;
                    q.push(node->right);
                }

                // Check parent
                if (parentTrack[node] && !visited[parentTrack[node]]) {
                    foundNew = true;
                    visited[parentTrack[node]] = true;
                    q.push(parentTrack[node]);
                }
            }

            if (foundNew) maxDist++;
        }

        return maxDist;
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parentTrack;
        TreeNode* target = bfsToMapParents(root, parentTrack, start);
        int time = findMaxDistance(parentTrack, target);
        return time;
    }
};
