描述
有2个排序好的数组，A[m]和B[n]，将其合并到A[m+n]中，使得A[m+n]也是排序好的。


思路
使用一个index = m + n -1，表示新数组的最后一个元素，然后i = m - 1；j = n - 1分别表示A[m]和B[n]的最后一个元素，依次比较A[i]和B[j]，选择大的把值写入到A[index]，然后index--，直到index < 0停止循环。要注意的是，m和n可能一个长一个短，就会出现一个数组先遍历完的情况，可以根据i或j < 0判断，然后把另一个数组的值依次往A[index]写就可以了。


代码
class Solution {
public:
    /**
     * @param A: sorted integer array A which has m elements, 
     *           but size of A is m+n
     * @param B: sorted integer array B which has n elements
     * @return: void
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
        int index = m + n - 1;
        int i = m - 1;
        int j = n - 1;
        while (index >= 0) {
            if (i < 0) {
                A[index--] = B[j--];
                continue;
            }
            if (j < 0) {
                A[index--] = A[i--];
                continue;                
            }
            if (A[i] >= B[j])
                A[index--] = A[i--];
            else
                A[index--] = B[j--];
        }
    }
};

