描述
对一个数字开平方。


思路
使用二分查找，查找范围是0-N，终止循环的条件是pow(mid, 2) == N || (pow(mid, 2) < N && pow(mid+1, 2) > N)。需要注意的是，如果用一个变量临时存pow(mid, 2)，应该使用long，防止溢出。还有就是，最后的return应该是永远不会执行的，所以返回-1。


代码
class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        int left = 0;
        int right = x;
        while (left <= right) {
            int mid = (left + right) / 2;
            long power = pow(mid, 2);
            if (power == x || (power < x && pow(mid + 1, 2) > x))
                return mid;
            if (power < x)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
};

