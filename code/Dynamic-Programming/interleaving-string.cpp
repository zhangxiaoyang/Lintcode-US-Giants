描述
有3个字符串s1、s2、s3，判断s3是否有s1和s2交叉组成。所谓的交叉就是，先从s1取若干字符，再从s2取若干字符，再从s1取若干字符，以此类推。


思路
dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (dp[i][j - 1] && s1[j - 1] == s3[i + j - 1])，其中dp[i][j]表示s1前i个字符和s2前j个字符能否组成s3的前i+j个字符。这里需要确定dp[0][.]和dp[.][0]是多少。对于dp[0][.]相当于只使用s2，所以dp[0][j] = dp[0][j - 1] && s2[j - 1] == s3[0+j-1]，dp[.][0]同理。所以，最后归结为dp[0][0]是多少呢？dp[0][1] = dp[0][0] && s2[0] == s3[0]，只需要判断s2的第一个元素是否和s3的第一个元素相等即可，所以dp[0][0]赋值为true。


代码
class Solution {
public:
    /**
     * Determine whether s3 is formed by interleaving of s1 and s2.
     * @param s1, s2, s3: As description.
     * @return: true of false.
     */
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        if (n1 + n2 != n3)
            return false;
            
        vector<vector<bool> > dp(n1 + 1, vector<bool>(n2 + 1, false));
        dp[0][0] = true;        
        for (int i = 1; i <= n1; i++)
            if (s1[i - 1] == s3[i - 1] && (i == 1 || dp[i - 1][0]))
                dp[i][0] = true;
        for (int j = 1; j <= n2; j++)
            if (s2[j - 1] == s3[j - 1] && (j == 1 || dp[0][j - 1]))
                dp[0][j] = true;
        
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1])
                    || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }
        return dp[n1][n2];
    }
};

