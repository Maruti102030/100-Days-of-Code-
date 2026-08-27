
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p==nullptr && q==nullptr) {
            return true;
        }
        if(p==nullptr || q==nullptr) {
            return false;
        }
        if(p->val != q->val) {
            return false;
        }
        bool r1 = isSameTree(p->left, q->left);
        bool r2 = isSameTree(p->right, q->right);
            if(r1 == true && r2 == true){
                return true;
            }
            return false;
    }
};