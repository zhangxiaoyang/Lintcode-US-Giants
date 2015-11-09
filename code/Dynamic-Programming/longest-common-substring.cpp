描述
求给定字符串A、B的最长公共子串，子串要求在字符串中连续。


思路
dp[i][j]表示A的前i个字符和B的前j个字符求得的公共子串长度，这里要求公共子串的尾部必须是A的第i个元素和B的第j个元素，即A[i - 1] == B[j - 1]。所以，dp[i][j] = dp[i - 1][j - 1] + 1 if A[i - 1] == B[j - 1] else 0


代码
class Solution {
public:    
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        int m = A.size(), n = B.size();
        vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
        int result = 0;
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (A[i - 1] == B[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                result = max(dp[i][j], result);
            }
        }
        return result;
    }
};

