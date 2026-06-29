class Solution {
public:
    int helper(TreeNode* root, int curr_sum) {

        if (root == nullptr) {
            return 0;
        }
        curr_sum = curr_sum * 10 + root->val;

        if (root->left == nullptr && root->right == nullptr) {
            return curr_sum;
        }
        int left_sum = helper(root->left, curr_sum);
        int right_sum = helper(root->right, curr_sum);
        
        return left_sum + right_sum;
    }
    
    int sumNumbers(TreeNode* root) {
        return helper(root, 0);
    }
};