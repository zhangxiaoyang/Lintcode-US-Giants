描述
合并2个有序的链表。


思路
使用一个dummy结点，curr->next存放来自有序链表的结点，不断遍历2个链表并把值小的结点放到curr->next。


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
     * @param ListNode l1 is the head of the linked list
     * @param ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy;
        ListNode* curr = &dummy;
        ListNode* p = l1;
        ListNode* q = l2;
        
        while (p != NULL || q != NULL) {
            if (p != NULL && q != NULL) {
                if (p->val < q->val) {
                    curr->next = p;
                    p = p->next;
                }
                else {
                    curr->next = q;
                    q = q->next;                
                }
            }
            else if (p != NULL) {
                curr->next = p;
                p = p->next;
            }
            else if (q != NULL) {
                curr->next = q;
                q = q->next;
            }
            curr = curr->next;
        }
        
        return dummy.next;
    }
};

