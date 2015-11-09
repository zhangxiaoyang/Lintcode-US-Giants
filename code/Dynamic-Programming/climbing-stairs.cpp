描述
有n个台阶，每次可以上1或2个，求总共有多少种上台阶的方法。


思路
dp[i] = dp[i - 1] + dp[i - 2]，即第i个台阶可以从i-1一步上来，也可以从i-2两步上来。


代码
class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n) {
        if (n == 0)
            return 1;
        if (n <= 2)
            return n;
        
        vector<int> dp(n, 0);
        dp[0] = 1;
        dp[1] = 2;
        for (int i = 2; i < n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n - 1];
    }
};

