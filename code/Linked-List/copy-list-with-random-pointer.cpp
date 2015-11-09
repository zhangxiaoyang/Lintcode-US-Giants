描述
深拷贝一个带random指针的链表。


思路
分三步：在原始链表的每一个结点后面都复制一个结点；遍历新链表，设置新加结点的random指针，使其指向前面结点的next；拆分2个链表。


代码
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        copyList(head);
        copyRandom(head);
        return extractCopyedList(head);
    }
    void copyList(RandomListNode* head) {
        RandomListNode* curr = head;
        while (curr != NULL) {
            RandomListNode* tmp = curr->next;
            curr->next = new RandomListNode(curr->label);
            curr->next->next = tmp;
            curr = curr->next->next;
        }
    }
    void copyRandom(RandomListNode* head) {
        RandomListNode* curr = head;
        while (curr != NULL) {
            if (curr->random != NULL)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }
    }
    RandomListNode* extractCopyedList(RandomListNode* head) {
        RandomListNode dummy;
        RandomListNode* p = head;
        RandomListNode* q = &dummy;
        while (p != NULL) {//important
            q->next = p->next;
            p->next = p->next->next;
            p = p->next;
            q = q->next;
        }
        return dummy.next;
    }
};

