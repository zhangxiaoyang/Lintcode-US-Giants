描述
自顶向下打印树，奇数层正序打印，偶数层逆序打印。


思路
可以使用queue，然后BFS，在偶数层reverse一下。还有更好的方法，即使用2个stack，不使用queue。


代码一（需要逆序）
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
     * @return: A list of lists of integer include 
     *          the zigzag level order traversal of its nodes' values 
     */
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if (root == NULL)
            return result;
            
        queue<TreeNode*> cache;
        cache.push(root);
        bool positive = true;
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
            if (!positive)
                reverse(row.begin(), row.end());
            result.push_back(row);
            positive = !positive;
        }
        return result;
    }
};


代码二（无需逆序）
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
     * @return: A list of lists of integer include 
     *          the zigzag level order traversal of its nodes' values 
     */
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if (root == NULL)
            return result;
            
        stack<TreeNode*> cache1;
        stack<TreeNode*> cache2;
        cache1.push(root);
        bool positive = true;
        while (!cache1.empty()) {
            vector<int> row;
            while (!cache1.empty()) {
                TreeNode* node = cache1.top();
                cache1.pop();
                row.push_back(node->val);
                if (positive) {
                    if (node->left != NULL)
                        cache2.push(node->left);
                    if (node->right != NULL)
                        cache2.push(node->right);
                }
                else {
                    if (node->right != NULL)
                        cache2.push(node->right);
                    if (node->left != NULL)
                        cache2.push(node->left);
                }
            }
            result.push_back(row);
            positive = !positive;
            
            stack<TreeNode*> tmp = cache2;
            cache2 = cache1;
            cache1 = tmp;
        }
        return result;
    }
};

