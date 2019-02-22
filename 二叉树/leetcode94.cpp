class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == nullptr) return {};
        Recurrence(res, root);
        return res;
    }
    
    void Recurrence(vector<int>& res, TreeNode* root){
        if(root == nullptr){
            return;  
        } 
        
        Recurrence(res, root->left);
        res.emplace_back(root->val);
        Recurrence(res, root->right);
    }
};
