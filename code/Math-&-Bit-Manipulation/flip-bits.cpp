描述
有2个数字，计算其二进制表示的不同的位数。如11111和01110，有2位不同。


思路
考虑到不同，把2个数字异或，异或之后只有不同的位置一。然后对异或得到的数字不断移位，判断每一位是否为1，为1则count++。这里需要注意，应该是使用左移，如果右移的话，负数的最高位“移不掉”。


代码
class Solution {
public:
    /**
     *@param a, b: Two integer
     *return: An integer
     */
    int bitSwapRequired(int a, int b) {
        int c = a ^ b;
        int count = 0;
        for (int i = 0; i < sizeof(int) * 8; i++) {
            if (c & 0x80000000)
                count++;
            c <<= 1;
        }
        return count;
    }
};

