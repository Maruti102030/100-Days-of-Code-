class Solution {
public:
    int dfs(TreeNode* root, int curr_sum) {
        if (root == nullptr) {
            return 0;
        }
        curr_sum = (curr_sum << 1) | root->val;
        if (root->left == nullptr && root->right == nullptr) {
            return curr_sum;
        }
        return dfs(root->left, curr_sum) + dfs(root->right, curr_sum);
    }

    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
};