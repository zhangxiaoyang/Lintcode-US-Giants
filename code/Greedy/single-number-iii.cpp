描述
有2n+2个数字，其中有n个数字出现2次，有2个不同的数字各出现一次，找不这2个不同的数字。


思路
先把所有的数字异或，得到一个数字，然后在得到的这个数字二进制表示中找到一个为1的位（随便找一位就可以，假设这一位是第x位，这个位可以区分要找的折2个数字，其他数字异或为0）。把所有数字x位为1的一起异或，为0的一起异或，这样会得到2个数，即为要找的数字。


代码
class Solution {
public:
    /**
     * @param A : An integer array
     * @return : Two integers
     */
    vector<int> singleNumberIII(vector<int> &A) {
        int num = 0;
        for (int i = 0; i < A.size(); i++) {
            num ^= A[i];
        }
        
        int diff = 1;
        while (!(diff & num)) {
            diff <<= 1;
        }
        
        vector<int> result(2, 0);
        for (int i = 0; i < A.size(); i++) {
            if (diff & A[i])
                result[0] ^= A[i];
            else
                result[1] ^= A[i];
        }
        sort(result.begin(), result.end());
        return result;
    }
};

