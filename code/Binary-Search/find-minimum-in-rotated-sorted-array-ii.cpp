描述
有一个经过旋转的有序数组，里面的元素可能有重复。从中找到最小的元素。


思路
通过二分查找找到转换点pivot，然后min(A[pivot], A[0])就是答案了。


代码
class Solution {
public:
    /**
     * @param num: the rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        int numLen = num.size();
        int pivot = searchPivot(num, numLen);
        if (pivot == -1)
            return num[0];
        return min(num[0], num[pivot]);
    }
    int searchPivot(vector<int>& A, int ALen) {
        int left = 0;
        int right = ALen - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (mid > 0 && A[mid] < A[mid - 1])
                return mid;
            if (mid < ALen - 1 && A[mid] > A[mid + 1])
                return mid + 1;
            if (A[mid] >= A[0])
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
};

