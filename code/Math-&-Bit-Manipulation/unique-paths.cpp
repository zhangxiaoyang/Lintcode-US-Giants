描述
有一个mxn的格子，从1,1位置走到m,n位置有多少种走法？


思路
可以看成一个组合的问题，横向一共走n-1，竖向一共走m-1步，所以一共走m+n-2步，组合数为C(m-1, m+n-2)。这种方法缺点是容易溢出。还可以使用动态规划的方法，dp[m][n]=dp[m-1][n]+dp[m][n-1]，dp[1][i]=1，dp[i][1]=1。


代码
class Solution {
public:
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    /*int uniquePaths(int m, int n) {
        vector<vector<int> > dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
        return dp[m - 1][n - 1];
    }*/
    int C(int n, int m) {
        long double num = 1;
        long double denom = 1;
        for (int i = 1; i <= min(n, m - n); i++) {
            num *= (m - i + 1);
            denom *= i;
        }
        return num / denom;
    }
    int uniquePaths(int m, int n) {
        return C(min(m - 1, n - 1), m + n - 2);
    } 
};

