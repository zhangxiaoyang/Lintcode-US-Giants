描述
给定一个数字数组（元素大于等于0且小于等于100），将其各个元素进行调整，使得相邻元素不超过target值，求最小的调整代价。


思路
dp[i][j] = min{dp[i - 1][k], k ∈ range(max{0, j - target}, min{100, j + target})} + abs(A[i] - j)，其中，dp[i][j]表示A[i]变成j且保证相邻元素不超过target需要的最小代价。所以，遍历dp[N-1][.]可以得到dp[N-1][k]，即为最后的结果。


代码
class Solution {
public:
    /**
     * @param A: An integer array.
     * @param target: An integer.
     */
    int MinAdjustmentCost(vector<int> A, int target) {
        int n = A.size();
        const int m = 100;
        vector<vector<int> > dp(n, vector<int>(m + 1, INT_MAX));
        
        for (int j = 0; j <= m; j++)
            dp[0][j] = abs(A[0] - j);
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= m; j++) {
                for (int k = max(0, j - target); k <= min(m, j + target); k++)
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + abs(A[i] - j));
            }
        }
        
        int result = INT_MAX;
        for (int j = 0; j <= m; j++)
            result = min(result, dp[n - 1][j]);            
        return result;
    }
};

