描述
重排链表，如1->2->3->4->null，则返回1->4->2->3->null，即第一个元素和最后一个元素连接，第二个元素和倒数第二个元素连接，以此类推。


思路
先把链表切分成两部分，把第二部分链表反转，再和第一部分合并。


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
     * @return: void
     */
    void reorderList(ListNode *head) {
        ListNode* left;
        ListNode* right;
        splitList(head, left, right);
        reverseList(right);
        head = mergeList(left, right);
    }
    void splitList(ListNode* head, ListNode*& left, ListNode*& right) {
        ListNode dummy;
        dummy.next = head;
        left = &dummy;
        right = &dummy;
        while (right != NULL && right->next != NULL) {
            left = left->next;
            right = right->next;
            if (right)
                right = right->next;
        }
        right = left->next;
        left->next = NULL;
        left = head;
    }
    void reverseList(ListNode*& head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
    ListNode* mergeList(ListNode* left, ListNode* right) {
        ListNode dummy;
        ListNode* curr = &dummy;
        ListNode* p = left;
        ListNode* q = right;
        while (p != NULL || q != NULL) {
            if (p != NULL) {
                curr->next = p;
                curr = p;
                p = p->next;
            }
            if (q != NULL) {
                curr->next = q;
                curr = q;
                q = q->next;
            }
        }
        return dummy.next;
    }
};

