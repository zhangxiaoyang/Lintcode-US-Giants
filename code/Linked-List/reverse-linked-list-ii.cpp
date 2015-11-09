描述
反转链表的指定连续区域。


思路
先遍历到要反转的位置，遍历的同时，记录prev和curr，把curr反转，然后再prev->next = curr。在反转curr的时候，要传入一个反转的结点个数，反转第一个结点时，记录下该结点tmp，最后需要将tmp->next连接到链表后面无需反转的部分。


代码
/**
 * Definition of singly-linked-list:
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @param m: The start position need to reverse.
     * @param n: The end position need to reverse.
     * @return: The new head of partial reversed linked list.
     */
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode dummy;
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* curr = head;
        for (int i = 1; curr != NULL; i++) {
            if (i >= m && i <= n) {
                prev->next = reverseList(curr, n - m + 1);
                break;
            }
            prev = prev->next;
            curr = curr->next;
        }
        return dummy.next;
    }
    ListNode* reverseList(ListNode* head, int length) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* tmp = NULL;
        for (int i = 0; i < length; i++) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            if (i == 0) {
                tmp = prev;    
            }
        }
        tmp->next = curr;
        return prev;
    }
};

