描述
删除链表倒数第k个结点。


思路
使用快慢指针，需要注意，可能删除链表的第一个节点，所以需要使用辅助头结点dummy。还可能删除的结点不存在，比如链表长度为3，删除倒数第9个结点，此时不做删除操作直接返回。


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
     * @return: The head of linked list.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode dummy;
        dummy.next = head;
        
        ListNode* slow = &dummy;
        ListNode* fast = &dummy;
        
        for (int i = 0; i <= n; i++) {
            if (fast == NULL)
                return head;
            fast = fast->next;
        }
        
        while (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* tmp = slow->next->next;
        delete slow->next;
        slow->next = tmp;
        return dummy.next;
    }
};

