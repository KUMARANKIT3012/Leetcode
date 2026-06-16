class Solution {
public:
    unordered_map<Node*, Node*> oldToNew;
    Node* dfs(Node* node) {
        if (oldToNew.count(node))
            return oldToNew[node];

        Node* copy = new Node(node->val);
        oldToNew[node] = copy;

        for (Node* nei : node->neighbors) {
            copy->neighbors.push_back(dfs(nei));
        }

        return copy;
    }

    Node* cloneGraph(Node* node) {
        if (node == nullptr)
            return nullptr;

        return dfs(node);
    }
};
