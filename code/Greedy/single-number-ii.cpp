描述
有一个数组，所有的数字都出现了3次，只有一个数字出现了1次，找出这个数字。


思路
把所有数字的各个位加起来，肯定每一位都是>=3，然后把每一位都mod3，得到的就是要找的数字。


代码
class Solution {
public:
 /**
  * @param A : An integer array
  * @return : An integer 
  */
    int singleNumberII(vector<int> &A) {
        const int limit = 32;
        vector<int> num(limit, 0);
        int result = 0;
        for (int i = 0; i < limit; i++) {
            for (int j = 0; j < A.size(); j++) {
                num[i] += (bool)(A[j] & (1 << i));
            }
            result |= (num[i] % 3) << i;
        }
        return result;
    }
};

