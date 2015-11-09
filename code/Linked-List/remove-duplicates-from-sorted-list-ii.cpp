描述
从链表中删除重复的元素，1->2->2->3->NULL，则变为1->3->NULL。


思路
遍历链表，然后判断当前节点是否与前一个或后一个相等，如果相等则删除。


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
class Solution{
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode * deleteDuplicates(ListNode *head) {
        ListNode dummy;
        ListNode* curr = &dummy;
        ListNode* p = head;
        int prev = INT_MIN;
        while (p != NULL) {
            ListNode* next = p->next;
            if (p->val != prev && (next == NULL || p->val != next->val)) {
                prev = p->val;
                curr->next = p;
                curr = curr->next;
                p = p->next;
            }
            else {
                prev = p->val;
                delete p;
                p = next;
            }
        }
        curr->next = NULL;
        return dummy.next;
    }
};

