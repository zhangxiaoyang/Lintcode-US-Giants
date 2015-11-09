描述
求树的根结点到最近叶子的层数。


思路
根到最近的叶子的层数 = (左孩子根结点到最近叶子的层数，右孩子根节点到最近叶子的层数)+1。注意，如果某个根结点没有左孩子，则只能去右边寻找。


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
     * @return: An integer
     */
    int minDepth(TreeNode *root) {
        if (root == NULL)
            return 0;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        if (left == 0)
            return right + 1;
        if (right == 0)
            return left + 1;
        return min(left, right) + 1;
    }
};

