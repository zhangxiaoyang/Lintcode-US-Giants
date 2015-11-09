描述
有一个有序数组，从数组中找到给定数值的下标。如果数组中没有给定的数值，那么就返回这个数值应该存储的下标。


思路
二分查找，如果没有找到，则最后返回left即可，因为left就表示应该存储的下标位置。


代码
class Solution {
    /** 
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &A, int target) {
        int ALen = A.size();
        int left = 0;
        int right = ALen - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (A[mid] == target)
                return mid;
            if (A[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
};

