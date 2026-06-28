class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;

        int leftH = getLeftHeight(root);
        int rightH = getRightHeight(root);

        // Agar dono heights same hain, toh perfect binary tree hai
        if (leftH == rightH) {
            return (1 << leftH) - 1; // Yaani 2^leftH - 1
        }

        // Agar perfect nahi hai, toh recursion use karo
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

private:
    int getLeftHeight(TreeNode* node) {
        int height = 0;
        while (node) {
            height++;
            node = node->left;
        }
        return height;
    }

    int getRightHeight(TreeNode* node) {
        int height = 0;
        while (node) {
            height++;
            node = node->right;
        }
        return height;
    }
};