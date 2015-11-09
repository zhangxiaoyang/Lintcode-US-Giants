描述
有一个二维数组，0表示可以走，1表示不可以走，求所有可能的路线个数（从左上角走到右下角）。


思路
先把dp初始化为全0，到i,j位置的所有路径数（i,j位置不为1)：if(dp[i - 1][j] == 0) dp[i][j] += dp[i - 1][j]; if（dp[i][j - 1] == 0) dp[i][j] += dp[i][j - 1]。


代码
class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */ 
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if (obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0)
            return 0;
            
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int> > dp(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 0) {
                    if (i == 0 && j == 0)
                        dp[i][j] = 1;
                    if (j > 0 && obstacleGrid[i][j - 1] == 0)
                        dp[i][j] += dp[i][j - 1];
                    if (i > 0 && obstacleGrid[i - 1][j] == 0)
                        dp[i][j] += dp[i - 1][j];
                }
            }
        }
        
        return dp[m - 1][n - 1];
    }
};

