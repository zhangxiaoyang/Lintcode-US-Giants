描述
反转链表，如1->2->3->4->NULL，给定k=2，则将后2个结点（3, 4)反转到链表前面，3->4->1->2->NULL。


思路
先找到倒数第k+1个结点，使用快慢指针即可。还要使用dummy头结点，因为倒数第k+1个结点可能是头结点的前面的结点，即链表有k个结点。然后A[k+1]->next = NULL，断开链表。快指针走到链表尾部，next=dummy.next。


代码
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: the list
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode *rotateRight(ListNode *head, int k) {
        k = k % listLen(head);
        
        if (k <= 0 || head == NULL)
            return head;
            
        ListNode dummy;
        dummy.next = head;
        ListNode* slow = &dummy;
        ListNode* fast = &dummy;
        for (int i = 0; i < k; i++) {
            if (fast == NULL)
                return head;
            fast = fast->next;
        }
        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        
        ListNode* next = slow->next;
        slow->next = NULL;
        if (next == dummy.next || next == NULL)
            return dummy.next;
        fast->next = dummy.next;
        return next;
    }
    int listLen(ListNode* head) {
        if (head == NULL)
            return -1;
        int count = 0;
        ListNode* p = head;
        while (p != NULL) {
            count++;
            p = p->next;
        }
        return count;
    }
};

