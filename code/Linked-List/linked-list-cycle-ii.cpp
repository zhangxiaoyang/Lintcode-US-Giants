描述
找出有环链表的环开始的结点。


思路
使用快慢指针，slow每次走一步，fast每次都两步，当slow == fast时，slow = head，然后slow和fast都走一步，相聚即为结点。
                  +-----+
                   |        |
--------------+-----x
      a                b
具体的证明是，假设slow和fast第一次相遇在x点，此时slow走了a+b，fast走了a+b+c+b，其中b+c=cycle。而(a+b)*2 = a+b+c+b，所以a和c相等。所以，把slow重置为head，然后slow和fast各走a步就相聚了。


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
     * @return: The node where the cycle begins. 
     *           if there is no cycle, return null
     */
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
            if (fast != NULL)
                fast = fast->next;
            if (slow == fast) {
                break;
            }
        }
        if (fast == NULL)
            return NULL;
            
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

