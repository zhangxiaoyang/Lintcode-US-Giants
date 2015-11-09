描述
从一个旋转的有序数组中找到给定的数值，数组元素会重复。


思路
使用和search in rotated sorted array一样的方法，先找到转换点。然后对转换点2侧的数组二分查找。


代码
class Solution {
    /** 
     * param A : an integer ratated sorted array and duplicates are allowed
     * param target :  an integer to be search
     * return : a boolean 
     */
public:
    bool search(vector<int> &A, int target) {
        int ALen = A.size();
        int pivot = searchPivot(A, ALen);
        if (pivot == -1)
            return bsearch(A, 0, ALen - 1, target);
        bool found = bsearch(A, 0, pivot - 1, target);
        if (!found)
            return bsearch(A, pivot, ALen - 1, target);
        return found;
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
    bool bsearch(vector<int>& A, int i, int j, int target) {
        int left = i;
        int right = j;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (A[mid] == target)
                return true;
            if (A[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};

