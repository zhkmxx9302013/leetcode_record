class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr ) return {};
        queue<TreeNode* > nodeQ; // BFS队列
        vector<vector<int>> res;
        nodeQ.push(root);
        
        while(!nodeQ.empty()){
            vector<int> layerRes; // 每一层的数据vector
            queue<TreeNode* > layerQ; // 可扩展节点队列
            while(!nodeQ.empty()){
                TreeNode* currNode = nodeQ.front();
                nodeQ.pop();
                layerRes.emplace_back(currNode->val);
                if(currNode->left)
                    layerQ.push(currNode->left);
                if(currNode->right)
                    layerQ.push(currNode->right);
            }
            // 同步可扩展节点队列到BFS队列
            while(!layerQ.empty()){
                nodeQ.push(layerQ.front());
                layerQ.pop();
            }
            res.emplace_back(layerRes);
        }
        return res;
    }
};
