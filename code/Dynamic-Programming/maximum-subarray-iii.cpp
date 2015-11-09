描述
给定一个数字数组，从中选择k个子数组（不相交），使得这k个子数组的和最大。


思路
dp[i][j]表示从前i个元素中取j个子数组求得的结果。dp[i][j] = max{dp[p][j - 1] + maxSubArray(A[p~END], 1), j - 1 <= p <= i - 1}。for (int p = i - 1; p >= j - 1; p--)这个为啥从后往前遍历，还没搞明白+_+


代码
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: An integer denote to find k non-overlapping subarrays
     * @return: An integer denote the sum of max k non-overlapping subarrays
     */
    int maxSubArray(vector<int> nums, int k) {
        int n = nums.size();
        vector<vector<int> > dp(n + 1, vector<int>(k + 1, 0));
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                dp[i][j] = INT_MIN;
                int tmp = 0;
                int maxOfRight = INT_MIN;
                for (int p = i - 1; p >= j - 1; p--) {
                    tmp = max(nums[p], tmp + nums[p]);
                    maxOfRight = max(tmp, maxOfRight);
                    if (dp[i][j] < dp[p][j - 1] + maxOfRight)
                        dp[i][j] = dp[p][j - 1] + maxOfRight;
                }
            }
        }
        return dp[n][k];
    }
};

