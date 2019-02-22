/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/////====递归解
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == nullptr) return {};
     
        Recurrence(res, root);
        return res;
    }
 
    void Recurrence(vector<int> &res, TreeNode* root){
        if(root == nullptr) return;
        res.emplace_back(root->val);
        Recurence(res, root->left);
        Recurence(res, root->right);
    }
};

////====循环解
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == nullptr) return {};
        stack<TreeNode* > transStack;
        
        TreeNode* currNode = root;
        while(true){
            res.emplace_back(currNode->val);
            if(currNode->right){
                transStack.push(currNode->right);
            }
            if(currNode->left){
                currNode = currNode->left;
            }else{
                if(!transStack.empty()){
                    currNode = transStack.top();
                    transStack.pop();
                }else{
                    currNode = nullptr;
                }
            }
            if(currNode == nullptr) break;
        }
        return res;
    }
};
