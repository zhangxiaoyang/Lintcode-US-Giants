描述
按层逆序打印树，即自底向上打印。


思路
使用queue进行BFS，最后reverse结果。（有没有不reverse的更好方法呢？）


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
     * @param root : The root of binary tree.
     * @return : buttom-up level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int> > result;
        if (root == NULL)
            return result;
            
        queue<TreeNode*> cache;
        cache.push(root);
        while(!cache.empty()) {
            int count = cache.size();
            vector<int> row;
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
        reverse(result.begin(), result.end());
        return result;
    }
};

