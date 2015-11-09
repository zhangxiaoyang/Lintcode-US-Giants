描述
有一个非负数组，每一个数字代表可以往下走的最大步数，问给定的数组能否从头走到尾。


思路
使用一个surplus（剩余可走步数）记录当前位置可以往后走的最大步数，只有在每一步的时候surplus都大于0，就说明可以走到尾部。


代码
class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: The boolean answer
     */
    bool canJump(vector<int> A) {
        int surplus = 1;
        for (int i = 0; i < A.size(); i++) {
            surplus -= 1;
            if (surplus < A[i])
                surplus = A[i];
            if (surplus == 0)
                return false;
        }
        return true;
    }
};

