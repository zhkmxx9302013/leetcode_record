///递归解法
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isSymmetrical(root, root);
    }
    
    bool isSymmetrical(TreeNode* pRoot1, TreeNode* pRoot2){
        if(pRoot1==nullptr && pRoot2==nullptr) return true;
        if(pRoot1==nullptr || pRoot2 == nullptr) return false;
        if(pRoot1->val != pRoot2->val) return false;
        return isSymmetrical(pRoot1->left, pRoot2->right) && isSymmetrical(pRoot1->right, pRoot2->left);
    }
    

};


/// BFS解法
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        stack<TreeNode*> Q;
        Q.push(root->left);
        Q.push(root->right);
        while(!Q.empty()){
            TreeNode* r1=Q.top();Q.pop();
            TreeNode* r2=Q.top();Q.pop();
            if(!r1 && !r2) continue;
            if(r1 && r2){
                if(r1->val != r2->val) return false;
                Q.push(r1->left);Q.push(r2->right);
                Q.push(r1->right);Q.push(r2->left);
            }else return false;
        }
        return true;
    }
};
