描述
删除有序链表中的重复值，只保留一个。


思路
使用一个dummy头结点，curr指向dummy，curr->next存放不重复的一个结点。不断的对输入链表相邻A[i]，A[i+1]比较，如果
A[i] == A[i+1]，则删除A[i]，继续比较A[i+1]和A[i+2]；如果A[i] != A[i+1]，则把A[i]加入到curr->next。


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
     * @return: head node
     */
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode dummy;
        ListNode* curr = &dummy;
        ListNode* p = head;
        while (p != NULL && p->next != NULL) {
            if (p->val == p->next->val) {
                ListNode* tmp = p;
                p = p->next;
                delete tmp;
            }
            else {
                curr->next = p;
                curr = curr->next;
                p = p->next;
            }
        }
        curr->next = p;
        return dummy.next;
    }
};

