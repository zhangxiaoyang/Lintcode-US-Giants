描述
判断一棵树是否是BST。


思路
BST是左子树的值都小于根的值，右子树的值都大于根的值。不能通过遍历树，判断左结点小于当前结点且右结点大于当前结点的方法判断，因为左结点小于当前结点不代表左结点的孩子都小于当前结点。具体可行的做法是，给每一个结点贴上2个值min和max，其孩子要保证在min和max之间。注意，初始的min和max用long类型，如果用int，结点值可能是INT_MAX。


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
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode *root) {
        return _isValidBST(root, LONG_MIN, LONG_MAX);        
    }
    bool _isValidBST(TreeNode* root, long min, long max) {
        if (root == NULL)
            return true;
            
        if (min < root->val && root->val < max)
            return _isValidBST(root->left, min, root->val)
                && _isValidBST(root->right, root->val, max);
        return false;
    }
};

