//把左子树作为右子树，并把 原右子树 拼接在 现右子树 的最右端
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == nullptr) return;
        
        flatten(root->left);
        flatten(root->right);
        
        // 找到叶节点(以子树为叶子)上一层，以便交换左右子树
        if(root->left != nullptr){
            TreeNode* right = root->right;
            root->right = root->left; //交换左子树到右子树位置
            root->left = nullptr;   //左子树置为空
            
            //遍历交换左子树之后得到的右子树，找到其右子树叶子节点，然后将交换前的右子树节点进行插入右子树操作。
            TreeNode* node = root->right; 
            while(node->right){
                node = node->right;
            }
            
            // 定位到末尾插入右子树
            node->right = right;
        }
    }
};
