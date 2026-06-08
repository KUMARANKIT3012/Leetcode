class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxpathdown(root, maxi);
        return maxi;
    }

    int maxpathdown(TreeNode* node, int &maxi){
        if(node == NULL) return 0;
        int left = max(0, maxpathdown(node->left, maxi));
        int right = max(0, maxpathdown(node->right, maxi));
        maxi = max(maxi, left + right + node->val);
        return max(left, right) + node->val;
    }
};




// another soln : 
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res = root->val;
        function<int(TreeNode*)> dfs = [&](TreeNode* root) {
            if(!root)
                return 0;
            int leftMax = dfs(root->left);
            int rightMax = dfs(root->right);
            leftMax = max(leftMax, 0);
            rightMax = max(rightMax, 0);
            res = max(res, root->val + leftMax + rightMax);
            return root->val + max(leftMax, rightMax);
        };
        dfs(root);
        return res;
    }
};
