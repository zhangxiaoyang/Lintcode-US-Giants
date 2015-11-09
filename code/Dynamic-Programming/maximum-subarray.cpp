描述
求数组的最大连续子数组，使得子数组的和最大。


思路
使用dp[i]表示前0~i个子数组的和，dp[i] = dp[i] + dp[i - 1] if dp[i - 1] >= 0 else dp[i] + 0。还可以只使用一个变量dp，dp随着遍历数组而改变，只记录0~i的子数组的值，如果大于result（初始化为INT_MIN），则修改result。


代码一
class Solution {
public:    
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
            
        vector<int> dp(n, 0);
        int result = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (i == 0)
                dp[i] = nums[i];
            else {
                if (dp[i - 1] < 0)
                    dp[i] = nums[i];
                else
                    dp[i] = dp[i - 1] + nums[i];
            }
            
            if (dp[i] > result)
                result = dp[i];
        }
        return result;
    }
};


代码二
class Solution {
public:    
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        int dp = 0;
        int result = INT_MIN;
        
        for (int i = 0; i < nums.size(); i++) {
            if (dp >= 0)
                dp += nums[i];
            else
                dp = nums[i];
            
            if (dp > result)
                result = dp;
        }
        return result;
    }
};

