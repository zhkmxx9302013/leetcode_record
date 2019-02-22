class Solution {
public:
    bool isSame(struct TreeNode* s, struct TreeNode* t)
    {
        if(!s && !t) // 两个子树叶子都是空
             return true;
        if(!s || !t) // 有一个不是空
            return false;
        if(s->val != t->val)
            return false;
        return isSame(s->left,t->left) && isSame(s->right,t->right);
    }
    bool isSubtree(struct TreeNode* s, struct TreeNode* t) {
        if(!s) // 主树为空
            return false;
        if((s->val == t->val) && isSame(s,t))
            return true;
        return isSubtree(s->left,t) || isSubtree(s->right,t);
    }
};
