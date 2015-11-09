描述
计算数字数组的最长递增序列长度，例如：[5, 4, 1, 2, 3]的最长递增序列为[1, 2, 3]，[4, 2, 4, 5, 3, 7]的最长递增序列为[4, 4, 5, 7]。


思路
dp[i]表示前i个数字所对应的最长递增子序列长度。所以，要想得到最长的，需要遍历dp[.]，然后找个一个最长的dp[i]。下一个问题是，如何计算dp[i]呢？dp[i] = max{dp[j], j < i && dp[j] <= dp[i]} + 1，即遍历dp[i]之前的每一个，然后看dp[j]是不是<=dp[i]，如果是，则太棒啦，dp[i]有可能等于dp[j] + 1，所以要用max选择一个。


代码
class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        int result = 0;
        
        for (int i = 1; i <= n; i++) {
            int tmp = 0;
            for (int j = 1; j < i; j++) {
                if (nums[j - 1] <= nums[i - 1])
                    tmp = max(dp[j], tmp);
            }
            dp[i] = tmp + 1;
            result = max(dp[i], result);
        }
        return result;
    }
};

