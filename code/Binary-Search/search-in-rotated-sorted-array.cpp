描述
从一个旋转的有序数组中找到给定的数值，数组元素不重复。


思路
数组的旋转，可能是原始的样子（有序），还可能是2半各自有序。先通过二分查找找到这个转换点，即A[i]<A[i-1]。然后再对以转换点为分割的两部分各自进行二分查找。


代码
class Solution {
    /** 
     * param A : an integer ratated sorted array
     * param target :  an integer to be searched
     * return : an integer
     */
public:
    int search(vector<int> &A, int target) {
        int ALen = A.size();
        int pivot = searchPivot(A, ALen);
        if (pivot == -1)
            return bsearch(A, 0, ALen - 1, target);
        int index = bsearch(A, 0, pivot - 1, target);
        if (index == -1)
            return bsearch(A, pivot, ALen - 1, target);
        return index;
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
    int bsearch(vector<int>& A, int i, int j, int target) {
        int left = i;
        int right = j;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (A[mid] == target)
                return mid;
            if (A[mid] <= target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
};

