描述
代码库有1~n个版本，现在确定里边有一个版本是坏的（isBadVersion = true），如果第i个版本是坏的，后面的新版本都是坏的（isBadVersion = true）。之前的好版本isBadVersion = false。现在是从里面找到第一个坏的版本编号。


思路
使用二分查找，可以理解为一个数组是0000111111，isBadVersion = true表示1。还是前面说的规律，left表示要查找的数的位置，这里是找1，left就是第一个1的下标。这里需要注意：left初始值为1，这个无所谓的，二分查找的时候，无论left从哪个下标开始（0也好，1页罢），结果一样，最终的left返回的值是一样的，就是应该存储1的位置，也就是第一次出现1的位置。


代码
/**
 * class VersionControl {
 *     public:
 *     static bool isBadVersion(int k);
 * }
 * you can use VersionControl::isBadVersion(k) to judge whether 
 * the kth code version is bad or not.
*/
class Solution {
public:
    /**
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        int left = 1;
        int right = n;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (!VersionControl::isBadVersion(mid))
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
};

