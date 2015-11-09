描述
给定{1,2,...,n}个数值，求构建出的BST有几种。


思路
假设BST的根是i，则左子树只能使用{1,2,...,i-1}构建，右子树只能使用{i+1,...,n}构建。所以可以使用动态规划求解，n<=1时，只有一种BST。


代码
class Solution {
public:
    /**
     * @paramn n: An integer
     * @return: An integer
     */
    int numTrees(int n) {
        vector<int> dp(n + 1, 1);// 0 ~ n
        for (int i = 2; i <= n; i++) {
            dp[i] = 0;
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};

