描述
将一个有序单链表转换成height balanced BST。


思路
找到单链表的中间结点mid，即BST的root。同理，在0~mid-1中找到中间结点，即root->left；mid+1~length-1中找到中间结点，即root->right。以此类推，递归执行。在超时代码中，找到mid是使用遍历的方法，每次找指定的mid，都要从单链表中遍历，会超时。为了解决这个问题，不使用遍历方法找mid，而是是buildTreeFromList中传入单链表的引用，即curr，每次构建好一个TreeNode，就curr = curr->next。构建Tree的方式是先构建左子树，再构建根，再构建右子树，刚好和curr的移动次序一致。


超时代码
/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
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
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    TreeNode *sortedListToBST(ListNode *head) {
        int length = listLen(head);
        buildTreeFromList(head, 0, length - 1);
    }
    TreeNode* buildTreeFromList(ListNode* head, int left, int right) {
        if (left > right)
            return NULL;
        
        int mid = (left + right) / 2;
        ListNode* p = head;
        for (int i = 0; i < mid; i++)
            p = p->next;
        TreeNode* root = new TreeNode(p->val);
        root->left = buildTreeFromList(head, left, mid - 1);
        root->right = buildTreeFromList(head, mid + 1, right);
        return root;
    }
    int listLen(ListNode* head) {
        int count = 0;
        while (head != NULL) {
            count++;
            head = head->next;
        }
        return count;
    }
};


代码
/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
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
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    TreeNode *sortedListToBST(ListNode *head) {
        int length = listLen(head);
        buildTreeFromList(head, 0, length - 1);
    }
    TreeNode* buildTreeFromList(ListNode*& curr, int left, int right) {
        if (left > right)
            return NULL;
        
        int mid = (left + right) / 2;
        TreeNode* leftTree = buildTreeFromList(curr, left, mid - 1);
        TreeNode* root = new TreeNode(curr->val);
        curr = curr->next;
        TreeNode* rightTree = buildTreeFromList(curr, mid + 1, right);
        root->left = leftTree;
        root->right = rightTree;
        return root;
    }
    int listLen(ListNode* head) {
        int count = 0;
        while (head != NULL) {
            count++;
            head = head->next;
        }
        return count;
    }
};

