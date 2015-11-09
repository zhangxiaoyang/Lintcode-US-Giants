描述
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]，从三角形的最顶部走到最低部，经过的数字和最小，且每次走只能往相邻的方向走。


思路
从下往上走，假设三角形的底部有x个元素，则开一个数组dp[x]，dp[j] = min(dp[j], dp[j + 1]) + triangle[current row index][j]。


代码
class Solution {
public:
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     */
    int minimumTotal(vector<vector<int> > &triangle) {
        int row = triangle.size();
        if (row == 0)
            return 0;
    
        vector<int> dp(triangle[row - 1].size(), 0);
        for (int i = row - 1; i >= 0; i--) {
            for (int j = 0; j < triangle[i].size(); j++) {
                if (i == row - 1)
                    dp[j] = triangle[i][j];
                else
                    dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
            }
        }
        return dp[0];        
    }
};

