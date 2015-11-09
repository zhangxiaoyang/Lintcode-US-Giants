描述
判断一颗二叉树是否平衡。


思路
平衡即任意一点的左子树高度和右子树的高度差小于等于1。要在每个结点上都测试，是否是平衡的，如果不是，则返回-1，上层结点就无需再判定了，直接返回false，否则则返回树的高度。


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
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
        return _isBalanced(root) == -1 ? false : true;
    }
    int _isBalanced(TreeNode* root) {
        if (root == NULL)
            return 0;
            
        int heightLeft = _isBalanced(root->left);
        int heightRight = _isBalanced(root->right);
        return heightLeft != -1
            && heightRight != -1
            && abs(heightLeft - heightRight) <= 1
            ? max(heightLeft, heightRight) + 1
            : -1;
    }
};

