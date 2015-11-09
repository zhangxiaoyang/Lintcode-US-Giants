描述
有奇数个数字，其中只有一个数字出现了一次，其他的都出现了2次，找出这个只出现一次的数。


思路
把所有的数字异或，结果就是只出现一次的数字。


代码
class Solution {
public:
 /**
  * @param A: Array of integers.
  * return: The single number.
  */
    int singleNumber(vector<int> &A) {
        int result = 0;
        for (int i = 0; i < A.size(); i++) {
            result ^= A[i];
        }
        
        return result;
    }
};

