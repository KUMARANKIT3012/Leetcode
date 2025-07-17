class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // Format: column -> row -> multiset of node values (to handle multiple nodes at same position)
        map<int, map<int, multiset<int>>> nodes;

        // Queue for BFS: stores (node, vertical level x, level y)
        queue<pair<TreeNode*, pair<int, int>>> todo;
        todo.push({root, {0, 0}});

        while (!todo.empty()) {
            auto p = todo.front();
            todo.pop();
            TreeNode* node = p.first;
            int x = p.second.first;  // vertical position
            int y = p.second.second; // level

            // Insert node value into the map
            nodes[x][y].insert(node->val);

            // Go left: x - 1 (left column), y + 1 (next level)
            if (node->left) 
                todo.push({node->left, {x - 1, y + 1}});
            
            // Go right: x + 1 (right column), y + 1 (next level)
            if (node->right) 
                todo.push({node->right, {x + 1, y + 1}});
        }

        // Prepare final answer
        vector<vector<int>> ans;
        for (auto& col : nodes) {
            vector<int> temp;
            for (auto& level : col.second) {
                temp.insert(temp.end(), level.second.begin(), level.second.end());
            }
            ans.push_back(temp);
        }

        return ans;
    }
};
