class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if (root == nullptr) return true;
        
        queue<TreeNode*> q;
        q.push(root);
        
        bool metNull = false;
        
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            
            if (curr == nullptr) {
                metNull = true; 
            } else {
                if (metNull) {
                    return false;
                }
                
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        
        return true;
    }
};