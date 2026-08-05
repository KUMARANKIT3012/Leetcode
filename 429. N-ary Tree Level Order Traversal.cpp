class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();
            vector<int> level;

            while (sz--) {
                Node* curr = q.front();
                q.pop();

                level.push_back(curr->val);

                for (Node* child : curr->children) {
                    q.push(child);
                }
            }

            ans.push_back(level);
        }

        return ans;
    }
};
