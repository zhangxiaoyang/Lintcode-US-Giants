描述
计算a^n%b，要求O(logn)时间。


思路
看到O(logn)应该想到二分查找，在这里，可以先计算half=fastPower(a, b, n/2)，再计算(half*half)%b。如果n不能整除2，则需要再乘上一项，即(half*half*a)%b。这里用到mod数学公式，即(ab)%n=(a%n * b%n)%n。


代码
class Solution {
public:
    /*
     * @param a, b, n: 32bit integers
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
        if (n == 0)
            return 1 % b;
        if (n == 1)
            return a % b;
        
        long half = fastPower(a, b, n / 2);
        long result = (half * half) % b;
        if (n & 1)
            result = (result * a) % b;
        return result;
    }
};

