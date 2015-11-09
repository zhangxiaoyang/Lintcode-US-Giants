描述
从前序和中序遍历序列构造一棵二叉树。


思路
前序的第一个元素是根，然后在中序中找到该结点，左侧是左子树，右侧是右子树。至此，就构造好了根，再递归的构造左子树和右子树，并把node->left和node->right指向构造好的左右子树。


代码一
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
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int i = 0;
        return _buildTree(preorder, i, inorder, 0, inorder.size() - 1);
    }
    TreeNode* _buildTree(vector<int>& preorder, int& i, vector<int>& inorder, int left, int right) {
        if (left > right) {
            i--;
            return NULL;
        }
        if (i >= preorder.size())
            return NULL;
            
        int value = preorder[i];
        TreeNode* root = new TreeNode(value);
        int index = find(inorder.begin(), inorder.end(), value) - inorder.begin();
        root->left = _buildTree(
            preorder,
            ++i,
            inorder,
            left,
            index - 1
        );
        root->right = _buildTree(
            preorder,
            ++i,
            inorder,
            index + 1,
            right
        );
        return root;
    }
};


代码二
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
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return _buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    TreeNode* _buildTree(vector<int>& preorder, int preBegin, int preEnd, vector<int>& inorder, int inBegin, int inEnd) {
        if (preBegin > preEnd)
            return NULL;
            
        int value = preorder[preBegin];
        TreeNode* root = new TreeNode(value);
        int index = find(inorder.begin(), inorder.end(), value) - inorder.begin();
        root->left = _buildTree(preorder, preBegin + 1, preBegin + index - inBegin, inorder, inBegin, index - 1);
        root->right = _buildTree(preorder, preBegin + index - inBegin + 1, preEnd, inorder, index + 1, inEnd);
        return root;
    }
};

