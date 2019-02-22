/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()|| inorder.empty())
            return nullptr;
        
        return TreeIterate(0, preorder.size() - 1, 0, inorder.size() - 1, preorder, inorder);
        
    }
    
    TreeNode* TreeIterate(int preL, int preR, int inL, int inR, const vector<int>& preorder, const vector<int>& inorder){
        if(preL > preR || inL > inR)
            return nullptr;
        
        int inRoot = 0; //中序遍历根节点位置
        
        for(int i = 0; i < inorder.size(); i++)
        {
            if(preorder[preL] == inorder[i]){
                inRoot = i;
                break;
            }
        }
        int num = inRoot - inL; //中序确定左子树节点数量
        
        TreeNode* currNode = new TreeNode(preorder[preL]);
        currNode -> left = TreeIterate(preL + 1, preL + num, inL, inRoot - 1 , preorder, inorder);
        currNode -> right = TreeIterate(preL + num + 1, preR, inRoot + 1, inR, preorder, inorder);
        return currNode;
    }
};
