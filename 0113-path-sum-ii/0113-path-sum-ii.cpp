class Solution {
public:
    void solve(TreeNode* root, int targetSum, vector<int>& currentPath, vector<vector<int>>& result) {
        if (root == nullptr) return;

        currentPath.push_back(root->val);

        if (root->left == nullptr && root->right == nullptr && targetSum == root->val) {
            result.push_back(currentPath);
        } else {
            solve(root->left, targetSum - root->val, currentPath, result);
            solve(root->right, targetSum - root->val, currentPath, result);
        }
        currentPath.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> currentPath;
        
        solve(root, targetSum, currentPath, result);
        
        return result;
    }
};