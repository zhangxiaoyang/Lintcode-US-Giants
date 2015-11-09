描述
判断链表中是否有环。


思路
使用快慢指针，快指针每次都2步，慢指针每次都1步，如果二者相遇，则有环。


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
     * @return: True if it has a cycle, or false
     */
    bool hasCycle(ListNode *head) {
        ListNode dummy;
        dummy.next = head;
        ListNode* slow = &dummy;
        ListNode* fast = &dummy;
        do {
            slow = slow->next;
            fast = fast->next;
            if (fast != NULL)
                fast = fast->next;
            else
                return false;
            if (slow == fast)
                return true;
        } while (fast != NULL);
        return false;
    }
};

