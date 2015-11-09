描述
求某个数阶乘所得结果中，尾部连续0的个数。例如，11! = 39916800，尾部连续出现了2个0，所以返回2。


思路
这个需要用数学的知识。考虑某个数的阶乘，尾部0的个数代表着这个数可以拆成2x5的个数。也就是说，阶乘运算后的结果，进行分解，得到的2x5的个数就是尾部0的个数。如何得到2x5的个数呢？首先可以确定，分解后的2要多于5，比如，1!有0个2和0个5，2!有1个2和0个5...依次类推，可以发现2的出现次数总是比5多。所以，可以只判断分解后的5的个数即可。对于n!，可以用n/5得出1~n中一共有几个数可以除尽5，这个结果加起来就是分解后的5的个数了！但是需要注意，有的数可以分解成多个5，比如25=5x5，所以我们还需要考虑n/(5x5)。最后得出计算公式，n/5+n/(5x5)+n/(5x5x5) ...


代码
class Solution {
 public:
    // param n : description of n
    // return: description of return 
    long long trailingZeros(long long n) {
        long long count = 0;
        long long divisor = 5;
        while (n / divisor) {
            count += n / divisor;
            divisor *= 5;
        }
        return count;
    }
};

