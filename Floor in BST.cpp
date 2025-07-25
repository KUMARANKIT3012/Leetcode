class Solution {
  public:
    int floor(Node* root, int x) {
        int ans = -1;

        while (root != NULL) {
            if (root->data == x) {
                return x; // exact match is the floor
            }
            else if (root->data < x) {
                ans = root->data;     // possible floor candidate
                root = root->right;   // try to find a bigger but still <= x
            }
            else {
                root = root->left;    // current node is too big
            }
        }

        return ans;
    }
};
