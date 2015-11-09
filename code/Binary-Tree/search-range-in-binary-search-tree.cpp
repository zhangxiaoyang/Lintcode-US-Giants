描述
给定一个数值范围，把BST中符合范围的数找出。


思路
判断当前结点是否符合，如果符合则保存下值，继续递归判断左右子树。如果不符合，则判断是去左子树递归还是右子树。


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
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
    vector<int> searchRange(TreeNode* root, int k1, int k2) {
        vector<int> result = _searchRange(root, k1, k2);
        sort(result.begin(), result.end());
        return result;
    }
    vector<int> _searchRange(TreeNode* root, int k1, int k2) {
        static vector<int> result;
        
        if (root == NULL)
            return result;
            
        if (k1 <= root->val && root->val <= k2) {
            result.push_back(root->val);
            searchRange(root->left, k1, k2);
            searchRange(root->right, k1, k2);
        }
        else if (root->val < k1)
            searchRange(root->right, k1, k2);
        else if (root->val > k2)
            searchRange(root->left, k1, k2);
        
        return result;
    }
};

