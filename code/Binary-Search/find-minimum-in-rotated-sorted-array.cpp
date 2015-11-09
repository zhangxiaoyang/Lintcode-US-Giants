描述
给定一个经过翻转的有序数组，找出最小的元素，数组元素不重复。


思路
翻转的一种情况是没翻转，如{1,2,3,4}。还一种情况是真的翻转了，如{3,4,1,2}。可以比较A[0]和A[N-1]来判断是否翻转了，对于第一种情况，可以直接返回A[0]。对于第二种情况，使用二分查找，查找的时候判断A[mid]是在左半部分，还是右半部分。如果在左边，那么就left = mid+1离开左边；如果在右边，那么就right = mid - 1继续像元素值小的地方前进。最后，left的位置就是最小值的位置。要始终铭记，left就是要查找的数的位置，如果没有这个数，就是应该放置这个数的位置。


代码
class Solution {
public:
    /**
     * @param num: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        int numLen = num.size();
        if (num[0] <= num[numLen - 1])
            return num[0];
            
        int left = 0;
        int right = numLen - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (num[mid] >= num[0])
                left = mid + 1;
            else
                right = mid - 1;
        }
        return num[left];
    }
};

