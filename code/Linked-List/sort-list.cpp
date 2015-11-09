描述
链表排序，要求O(nlogn)时间。


思路
使用快速排序或归并排序。在lintcode中快速排序会超时。


超时代码（quicksort）
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
     * @return: You should return the head of the sorted linked list,
                    using constant space complexity.
     */
    ListNode *sortList(ListNode *head) {
        return quicksort(head);
    }
    // QuickSort
    // Return newHead of sorted list
    ListNode* quicksort(ListNode* head) {
        if (head == NULL)
            return NULL;
        ListNode* L1;
        ListNode* L2;
        ListNode* pivot = partition(head, L1, L2);
        ListNode* newHead = quicksort(L1);
    
        //timeout
        ListNode* p = newHead;
        if (p != NULL) {
            while (p->next != NULL)
                p = p->next;
            p->next = pivot;
        }
        else
            newHead = pivot;
            
        pivot->next = quicksort(L2);
        return newHead;        
    }
    ListNode* partition(ListNode* head, ListNode*& L1, ListNode*& L2) {
        ListNode* pivot = head;
        ListNode* curr = head->next;
        ListNode leftList, rightList;
        ListNode* p = &leftList;
        ListNode* q = &rightList;
        while (curr != NULL) {
            if (curr->val <= pivot->val) {
                p->next = curr;
                p = p->next;
            }
            else {
                q->next = curr;
                q = q->next;
            }
            curr = curr->next;
        }
        p->next = NULL;
        q->next = NULL;
        L1 = leftList.next;
        L2 = rightList.next;
        return pivot;
    }
};


代码（mergesort）
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
     * @return: You should return the head of the sorted linked list,
                    using constant space complexity.
     */
    ListNode *sortList(ListNode *head) {
        return mergesort(head);
    }
    ListNode* mergesort(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
            
        ListNode* mid = splitList(head);
        ListNode* left = mergesort(head);
        ListNode* right = mergesort(mid);
        return mergeList(left, right);
    }
    ListNode* splitList(ListNode* head) {
        ListNode dummy;
        dummy.next = head;
        ListNode* slow = &dummy;
        ListNode* fast = &dummy;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
            if (fast != NULL)
                fast = fast->next;
        }
        ListNode* mid = slow->next;
        slow->next = NULL;
        return mid;
    }
    ListNode* mergeList(ListNode* left, ListNode* right) {
        ListNode dummy;
        ListNode* curr = &dummy;
        ListNode* p = left;
        ListNode* q = right;
        while(p != NULL || q != NULL) {
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

