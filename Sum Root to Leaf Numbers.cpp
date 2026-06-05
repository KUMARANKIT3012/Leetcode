class Solution {
public:
    int dfs(TreeNode* curr, int num){
        if(!curr){
            return 0;
        }
        num = num * 10 + curr->val;
        if(!curr->left and !curr->right){
            return num;
        }
        return dfs(curr->left, num) + dfs(curr->right, num);
    }

    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};
