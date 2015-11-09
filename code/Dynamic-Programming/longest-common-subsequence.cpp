描述
计算A和B的最长公共子序列，子序列无需在A或B中连续。


思路
dp[i][j]表示A的前i个字符和B的前j个字符求得的最长公共子序列长度。dp[i][j] = dp[i - 1][j - 1] + 1 if A[i - 1] == B[j - 1] else max{dp[i - 1][j], dp[i][j - 1]}。当A[i - 1] == B[j - 1]时，可以直接加上dp[i - 1][j - 1]，因为此时肯定能让子序列更长。否则，dp[i][j] = max{dp[i][j - 1], dp[i - 1][j]}，因为A[i - 1]和B[j - 1]肯定是无法称为子序列的最后一个字符了，所以只能通过max选一个。


代码
class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int longestCommonSubsequence(string A, string B) {
        int m = A.size(), n = B.size();
        vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = A[i - 1] == B[j - 1]
                    ? dp[i - 1][j - 1] + 1
                    : max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m][n];
    }
};

