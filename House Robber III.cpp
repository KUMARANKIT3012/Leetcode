class Solution {
public:
    pair<int,int> dfs(TreeNode* root){
        if(!root){
            return {0, 0};
        }
        auto leftPair = dfs(root->left);
        auto rightPair = dfs(root->right);
        int withRoot = root->val + leftPair.second + rightPair.second;
        int withoutRoot = max(leftPair.first, leftPair.second) +
        max(rightPair.first, rightPair.second);
        return {withRoot, withoutRoot};
    }

    int rob(TreeNode* root) {
        auto ans = dfs(root);
        return max(ans.first, ans.second);
    }
};
