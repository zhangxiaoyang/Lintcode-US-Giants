描述
有2个数，N和M，把M“插入”到N中的指定位置。例如，N=(10000000000)2, M=(10101)2, i=2, j=6，则返回N=(10001010100)2。


思路
通过二进制位操作来解决。首先把N中的指定位置清空，使用把1左移然后减1的方式，可以得到一串1，然后再把这一串1左移与N进行与操作即可。然后，把给定的数左移，与清空后的N进行或操作。需要注意的是，第一步清空的时候，如果给定的返回是i~31，即最高位，那么再左移减1就不对了，已经到最左侧了。此时，需要单独对待。


代码
class Solution {
public:
    /**
     *@param n, m: Two integer
     *@param i, j: Two bit positions
     *return: An integer
     */
    int updateBits(int n, int m, int i, int j) {
        int mask;
        if (j < 31)
            mask = ~(((1 << (j - i + 1)) - 1) << i);
        else
            mask = (1 << i) - 1;
        return (n & mask) | (m << i);
    }
};

