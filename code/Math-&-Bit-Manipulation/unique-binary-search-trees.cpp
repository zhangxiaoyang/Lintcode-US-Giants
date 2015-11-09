描述
给定一个数字N，求以1,2...N为节点值组成的BST的种类数目。


思路
结果是一个卡特兰数，但是一下子想到的是动态规划。设dp[i]为1,2...i为节点组成的BST的种类数目，则dp[i]=sum(dp[j] * dp[i - j - 1])，j<i，表示左侧可能的BST个数乘以右侧的，一共i个元素，左侧有j个，根部一个，则右侧有i-j-1个。终止条件是，dp[0]=1。


代码
class Solution {
public:
    /**
     * @paramn n: An integer
     * @return: An integer
     */
    int numTrees(int n) {
        vector<int> count(n + 1, 0);
        count[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                count[i] += count[j] * count[i - j -1];
            }
        }
        return count[n];
    }
};

