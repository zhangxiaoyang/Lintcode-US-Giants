描述
把一个结点插入到一颗BST中。


思路
如果node->left == NULL && value < node->val，则node->left  = new TreeNode(value)；如果node->right == NULL && value > node->val，则node->right = new TreeNode(value)。否则递归寻找可以插入的结插入。


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
public:
    /**
     * @param root: The root of the binary search tree.
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode* insertNode(TreeNode* root, TreeNode* node) {
        if (root == NULL)
            return node;
        
        if (node->val < root->val) {
            if (root->left == NULL)
                root->left = node;
            else
                insertNode(root->left, node);
        }
        else if (node->val > root->val) {
            if (root->right == NULL)
                root->right = node;
            else
                insertNode(root->right, node);
        }
        return root;
    }
};

