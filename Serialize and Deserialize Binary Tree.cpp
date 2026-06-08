/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "null";

        string result;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node) {
                result += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            } else {
                result += "null,";
            }
        }

        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "null") return NULL;

        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            getline(s, str, ',');
            if (str != "null") {
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

            getline(s, str, ',');
            if (str != "null") {
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));










class Codec {
public:
    string serialize(TreeNode* root) {
        vector<string> res;

        function<void(TreeNode*)> dfs = [&](TreeNode* node) {
            if(!node) {
                res.push_back("N");
                return;
            }

            res.push_back(to_string(node->val));
            dfs(node->left);
            dfs(node->right);
        };

        dfs(root);

        string ans = "";
        for(int i = 0; i < res.size(); i++) {
            ans += res[i];
            if(i != res.size() - 1)
                ans += ",";
        }

        return ans;
    }

    TreeNode* deserialize(string data) {
        vector<string> vals;
        string temp;

        for(char c : data) {
            if(c == ',') {
                vals.push_back(temp);
                temp = "";
            } else {
                temp += c;
            }
        }

        vals.push_back(temp);

        int i = 0;

        function<TreeNode*()> dfs = [&]() {
            if(vals[i] == "N") {
                i++;
                return (TreeNode*)NULL;
            }

            TreeNode* node = new TreeNode(stoi(vals[i]));
            i++;

            node->left = dfs();
            node->right = dfs();

            return node;
        };

        return dfs();
    }
};
