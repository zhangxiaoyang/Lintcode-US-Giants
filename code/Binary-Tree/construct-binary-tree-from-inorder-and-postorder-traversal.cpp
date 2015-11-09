描述
中序和后序序列构建二叉树。


思路
后序序列的最后一个结点是根，即后序的模式是：左右根；而中序的模式是左根右。


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
     *@param inorder : A list of integers that inorder traversal of a tree
     *@param postorder : A list of integers that postorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int i = postorder.size() - 1;
        return _buildTree(inorder, 0, inorder.size() - 1, postorder, i);
    }
    
    TreeNode* _buildTree(vector<int> &inorder, int inBegin, int inEnd, vector<int> &postorder, int& i) {
        if (i < 0)
            return NULL;
        if (inBegin > inEnd) {
            i++;
            return NULL;
        }
            
        int value = postorder[i];
        int index = find(inorder.begin(), inorder.end(), value) - inorder.begin();
        
        TreeNode* root = new TreeNode(value);
        root->right = _buildTree(inorder, index + 1, inEnd, postorder, --i);
        root->left = _buildTree(inorder, inBegin, index - 1, postorder, --i);
        return root;
    }
};

