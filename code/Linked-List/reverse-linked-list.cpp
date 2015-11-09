描述
反转链表。


思路
使用一个prev，最开始指向NULL，然后遍历链表，不断的把结点指向prev，再移动prev。


代码
/**
 * Definition of ListNode
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 * 
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
     * @return: The new head of reversed linked list.
     */
    ListNode *reverse(ListNode *head) {
        ListNode* prev = NULL;
        ListNode* p = head;
        
        while (p != NULL) {
            ListNode* next = p->next;
            p->next = prev;
            prev = p;
            p = next;
        }
        return prev;
    }
};

