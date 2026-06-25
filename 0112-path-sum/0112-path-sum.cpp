class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // Base Case 1: Agar tree khali hai, toh koi path possible hi nahi hai
        if (root == nullptr) {
            return false;
        }
        
        // Base Case 2: Agar hum leaf node par hain, toh check karo ki bacha hua sum iski value ke barabar hai ya nahi
        if (root->left == nullptr && root->right == nullptr) {
            return root->val == targetSum;
        }
        
        // Naya target calculate karo current node ki value minus karke
        int remainingSum = targetSum - root->val;
        
        // Left ya Right dono mein se kisi bhi ek taraf agar valid path mil jata hai toh true return karo
        return hasPathSum(root->left, remainingSum) || hasPathSum(root->right, remainingSum);
    }
};