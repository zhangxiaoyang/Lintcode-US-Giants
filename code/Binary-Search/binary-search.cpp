描述
查找给定的数是否在一个有序数组中，返回第一次出现这个数的下标，注意：数组的元素可能会重复。


思路
可以使用二分查找，关键是如何处理重复的元素。关键点在：if(A[mid] >= target) right = mid - 1;因为最后算出来的left会是期待存放target的位置，我们只需要再判断A[left]是否等于target，如果等于，left就是第一次出现target的位置了。否则返回-1。


代码
class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0. 
     */
    int binarySearch(vector<int> &array, int target) {
        int left = 0;
        int right = array.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (array[mid] >= target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return array[left] == target ? left : -1;
    }
};

