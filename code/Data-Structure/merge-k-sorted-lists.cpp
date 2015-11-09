描述
合并k个有序的链表。


思路
使用mergesort的方法，递归合并。


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
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        return _mergeKLists(lists, 0, lists.size() - 1);
    }
    ListNode* _mergeKLists(vector<ListNode*>& lists, int from, int to) {
        if (from > to)
            return NULL;
        if (from == to)
            return lists[from];
        
        int mid = (from + to) / 2;
        ListNode* list1 = _mergeKLists(lists, from, mid);
        ListNode* list2 = _mergeKLists(lists, mid + 1, to);
        
        ListNode dummy;
        ListNode* p = &dummy;
        while (list1 != NULL || list2 != NULL) {
            if (list1 != NULL && list2 != NULL) {
                if (list1->val <= list2->val) {
                    p->next = list1;
                    list1 = list1->next;
                }
                else {
                    p->next = list2;
                    list2 = list2->next;
                }
            }
            else if (list1 != NULL) {
                p->next = list1;
                list1 = list1->next;
            }
            else if (list2 != NULL) {
                p->next = list2;
                list2 = list2->next;
            }
            p = p->next;
        }
        p->next = NULL;
        return dummy.next;
    }
};

