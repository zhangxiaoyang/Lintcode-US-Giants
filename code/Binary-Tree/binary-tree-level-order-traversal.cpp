描述
按层次遍历二叉树。


思路
使用BFS的方式，用一个队列模拟。


代码
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
 
 
class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: Level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if (root == NULL)
            return result;
            
        queue<TreeNode*> cache;
        cache.push(root);
        while (!cache.empty()) {
            vector<int> row;
            int count = cache.size();
            for (int i = 0; i < count; i++) {
                TreeNode* node = cache.front();
                cache.pop();
                row.push_back(node->val);
                
                if (node->left != NULL)
                    cache.push(node->left);
                if (node->right != NULL)
                    cache.push(node->right);
                
            }
            result.push_back(row);
            
        }
        return result;
    }
};

