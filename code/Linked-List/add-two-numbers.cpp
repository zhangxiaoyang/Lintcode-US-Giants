描述
两个链表相加，7->1->6 + 5->9->2 = 617 + 295 = 2->1->9。


思路
需要有一个进位变量carry，每次相加后都把进位存储到carry中，最后遍历完链表后，判断carry是否大于0，如果大于0
，则新建一个结点。


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
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2 
     */
    ListNode *addLists(ListNode *l1, ListNode *l2) {
        ListNode dummy;
        ListNode* curr = &dummy;
        ListNode* p = l1;
        ListNode* q = l2;
        int carry = 0;
        while (p != NULL || q != NULL) {
            int num = carry;
            if (p != NULL) {
                num += p->val;
                p = p->next;
            }
            if (q != NULL) {
                num += q->val;
                q = q->next;
            }
                
            curr->next = new ListNode(num % 10);
            carry = num / 10;
            curr = curr->next;
        }
        if (carry)
            curr->next = new ListNode(carry);
        return dummy.next;
    }
};

