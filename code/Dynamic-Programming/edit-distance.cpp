描述
计算2个字符串的编辑距离，一次插入、删除、替换记为距离1。


思路
dp[i][j]表示两个字符串0~i和0~j子串的编辑距离。dp[i][j] = dp[i - 1][j - 1] if word1[i] == word2[j]这个很好理解，如果要比较的字符串尾部一样，就看前面的编辑距离。如果word1[i] != word2[j]，则可能存在3种情况：
1. dp[i][j - 1] + 1，word1[0~i] == word2[0~j-1]，所以word1少一个字符，需要执行插入操作。
2. 1 + dp[i - 1][j]，word1[0~i-1] == word2[0~j]，所以word1多一个字符，需要执行删除操作。
3. dp[i - 1][j - 1] + 1，word1[0~i-1] == word2[0~j-1]，所以word1和word2只有最后一个字符不同，需要执行替换操作。
将3者求min即可。


代码
class Solution {
public:    
    /**
     * @param word1 & word2: Two string.
     * @return: The minimum number of steps.
     */
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        
        if (m == 0)
            return n;
        if (n == 0)
            return m;
            
        vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= m; i++)
            dp[i][0] = i;
        for (int j = 0; j <= n; j++)
            dp[0][j] = j;
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int replace = dp[i - 1][j - 1] + 1;
                int remove = 1 + dp[i - 1][j];
                int insert = dp[i][j - 1] + 1;
                
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(min(replace, remove), insert);
            }
        }
        return dp[m][n];
    }
};

