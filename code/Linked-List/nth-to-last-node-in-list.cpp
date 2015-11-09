描述
返回链表的倒数第n个结点。


思路
使用快慢指针，快指针先走n个结点。


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
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @param n: An integer.
     * @return: Nth to last node of a singly linked list. 
     */
    ListNode *nthToLast(ListNode *head, int n) {
        ListNode dummy;
        dummy.next = head;
        ListNode* slow = &dummy;
        ListNode* fast = &dummy;
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        while (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

