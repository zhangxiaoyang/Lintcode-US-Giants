描述
对链表执行类似quicksort的partition操作，小于给定元素x，则放到左边，否则放到右边。左边的元素要保持在原始链表中的顺序，右边同样。


思路
使用2个dummy头结点，分别是left和right，最后再把left和right连接起来。需要注意，right的最后一个结点的next要指向NULL，因为在原始的链表中该结点可能指向某个结点，这样就会有环了。


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
     * @param x: an integer
     * @return: a ListNode 
     */
    ListNode *partition(ListNode *head, int x) {
        ListNode left;
        ListNode right;
        ListNode* p = head;
        ListNode* currLeft = &left;
        ListNode* currRight = &right;
        while (p != NULL) {
            if (p->val < x) {
                currLeft->next = p;
                currLeft = currLeft->next;
            }
            else {
                currRight->next = p;
                currRight = currRight->next;
            }
            p = p->next;
        }
        currLeft->next = right.next;
        currRight->next = NULL;//important
        return left.next;
    }
};

