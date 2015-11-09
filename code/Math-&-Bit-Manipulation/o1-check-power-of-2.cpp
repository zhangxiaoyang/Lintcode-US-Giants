描述
判断给定的数字是否为2的n次幂。


思路
一个数字如果是2的n次幂，那么他的二进制表示就只有一个位置1。所以，可以遍历这个数字的每一位，看一下有几个位置1。需要注意，如果是负数，则直接判断其不是2的n次幂。还有一个方法，直接return （n & (n-1)) == 0 ? true : false，原理是如果是2的n次幂，那么n的二进制有1个1，n-1的置1位一定与n的不同；如果不是2的n次幂，那么肯定有大于1个位置1，n-1的置1位一定与n的置1位有相同的。需要注意，第二种方法仍要处理输入为负数或0的情况，比如（0 & -1) == 0。


代码
class Solution {
public:
    /*
     * @param n: An integer
     * @return: True or false
     */
    bool checkPowerOf2(int n) {
        if (n <= 0)
            return false;
        return (n & (n - 1)) == 0 ? true : false;
    }
};

