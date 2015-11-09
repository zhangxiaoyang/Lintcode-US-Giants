描述
从S删除若干字符变成T，有多少种删除方式。


思路
dp[i][j]表示从S[0~i]变成T[0~j]的删除方式。如果S[i] != T[j]，则dp[i][j] = dp[i - 1][j]（只能通过S[0~i-1]变成T[0~j]）。如果S[i] == T[j]，则dp[i][j] = dp[i - 1][j - 1]（使用S[i]进行匹配） + dp[i - 1][j]（不使用S[i]进行匹配）。


代码
class Solution {
public:    
    /**
     * @param S, T: Two string.
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string &S, string &T) {
        int m = S.size();
        int n = T.size();
        vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 0; i <= m; i++)
            dp[i][0] = 1;
            
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (S[i - 1] == T[j - 1])
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[m][n];
    }
};

