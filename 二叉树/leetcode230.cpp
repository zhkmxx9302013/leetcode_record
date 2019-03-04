class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> transStack;
        while(1){
            if(root != NULL){
                transStack.push(root);
                root = root->left;
            } else {
                if(--k == 0){
                    return transStack.top()->val;
                } else {
                    root = (transStack.top())->right;
                    transStack.pop();
                }
            }
        }
    }
};
