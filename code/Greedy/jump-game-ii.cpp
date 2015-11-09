描述
给定一个数组，数组的每个元素代表可以往后走的步数，求最少几跳可以到达最后一个元素。


思路
遍历数组，每次都求出截止到当前元素可以跳的最远位置curr = max(curr, i + A[i])。如果i > curr，说明0~i-1的任何元素都不能一次跳到i的位置，即返回-1。如果i > last，也就是i == last + 1，此时终于走出了上一次跳的范围，可以进行下一跳了，即last = curr，其中curr是last（0~i - 1）可以跳到的位置。


代码
class Solution {
public:
    /**
     * @param A: A list of lists of integers
     * @return: An integer
     */
    int jump(vector<int> A) {
        int curr = 0;
        int last = 0;
        int result = 0;
        for (int i = 0; i < A.size(); i++) {
            if (i > curr)
                return -1;
            if (i > last) {
                last = curr;
                result++;
            }
            curr = max(curr, i + A[i]);
        }
        return result;
    }
};

