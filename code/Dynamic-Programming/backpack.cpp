描述
背包问题，给定一个数组，代表物品大小；还有一个值，代码书包的大小。求书包可以放的最多的物品个数。


思路
dp[i][j] = max{dp[i - 1][j], dp[i - 1][j - A[i - 1]] + A[i - 1]}，其中，dp[i][j]表示从前i个物品中blabla，最后书包放下的最大数目存在dp[i][j]中。对于N个物品，dp[0~N][.]的行又“牺牲”了第0行，但是这样会方便许多。同时，把转移方程变成：dp[i + 1][j] = max{dp[i][j], dp[i][j - A[i]] + A[i]},在循环的时候，i from 0 to N - 1，j from - to M。还需要确定dp[0][.]的值，因为dp[1][.]完全依赖dp[0][.]算出来，dp[0][.]表示前0个物品，即没有物品，所以dp[0][.]全初始为0。按照此方法的代码一超时了。原因在于使用的dp是二维数组。
解决方法使用一维的数组。在上面有写到，“dp[1][.]完全依赖dp[0][.]算出来”，即dp[i+1][.]完全依赖于dp[i][.]，所以我们可以这样，只用一个dp[1 + M]的数组，随着按行遍历，先写dp[0][.]的结果，然后再覆盖写dp[1][.]的结果，以此类推，只要保证在写的时候，需要用的上一行的值还没有被覆盖就可以了。从dp[i + 1][j] = max{dp[i][j], dp[i][j - A[i]] + A[i]}中可以发现，dp[.][j]依赖于dp[.][j]和dp[.][j - x]，所以只要我们从dp[1 + M]的右边开始写，就妥妥的没问题了！所以，dp[j] = max(dp[j], dp[j - A[i]] + A[i]}，需要注意，如果j < A[i]，那么就不用更新dp[j]了，使用上一行的即可。


代码一（超时）
class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
        int n = A.size();
        vector<vector<int> > dp(1 + n, vector<int>(1 + m, 0));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= m; j++) {
                if (j < A[i])
                    dp[i + 1][j] = dp[i][j];
                else
                    dp[i + 1][j] = max(dp[i][j], dp[i][j - A[i]] + A[i]);
            }
        }
        return dp[n][m];
    }
};


代码二
class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
        int n = A.size();
        vector<int> dp(1 + m, 0);
        
        for (int i = 0; i < n; i++) {
            for (int j = m; j >= A[i]; j--) {
                dp[j] = max(dp[j], dp[j - A[i]] + A[i]);
            }
        }
        return dp[m];
    }
};

