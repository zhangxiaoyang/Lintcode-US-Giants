描述
求2个字符串A和B的最长公共子串，注意不是子序列。


思路
使用动态规划解决 s[i, j]表示以i下标结尾的A子串a和以j下标结尾的B子串b，a和b的最长公共子串。所以，只有A[i] == B[i]，a和b才会有最长公共子串，否则为0。s[i, j] = s[i-1, j-1] + 1 if A[i] == B[j] else 0。为了方便计算，使用的数组为dp[ALen+1][BLen+1]，新添加的第0行和第0列，可以直接得出dp[0][.] = 0，dp[.][0] = 0。


代码
class Solution {
public:    
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        int ALen = A.size();
        int BLen = B.size();
        vector<vector<int> > dp(ALen + 1, vector<int>(BLen + 1, 0));
        
        int result = 0;
        for (int i = 0; i < ALen + 1; i++) {
            for (int j = 0; j < BLen + 1; j++) {
                if (!i || !j)
                    dp[i][j] = 0;
                else if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    result = max(result, dp[i][j]);
                }
                else
                    dp[i][j] = 0;
            }
        }
        return result;
    }
};

