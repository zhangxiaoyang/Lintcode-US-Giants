描述
找到数组的peak下标（元素比左边和右边的值都大），比如{1, 2, 1, 3, 4, 5, 7, 6}，peak是2和7，下标分别是1和6。数组还有一个限制：相邻的数不同；A[0] < A[1] && A[A.length - 2] > A[A.length - 1].


思路
使用二分查找，找到比左右都大的值则返回，否则继续二分。需要注意的是，题目简化了很多，因为A[0] < A[1] && A[A.length - 2] > A[A.length - 1]，表示不会出现这种情况{3,2,1,5,6}。如果出现这种情况，3,2,1这段就不好弄了，因为按照查找策略，找到2后，会继续“爬坡”，从2之前的部分找，但是2之前的部分没有山顶了，3不是山顶，因为左边没有元素了。


代码
class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> A) {
        int ALen = A.size();
        int left = 0;
        int right = ALen - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (mid > 0 && mid < ALen - 1 && A[mid] > A[mid - 1] && A[mid] > A[mid + 1])
                return mid;
            else if (mid < ALen - 1 && A[mid] >= A[mid + 1])
                right = mid - 1;
            else if (mid < ALen - 1 && A[mid] < A[mid + 1])
                left = mid + 1;
            else if (mid > 0 && A[mid] >= A[mid - 1])
                left = mid + 1;
            else if (mid > 0 && A[mid] < A[mid - 1])
                right = mid - 1;
        }
        return -1;
    }
};

