描述
从整数数组中选择2个子数组A、B（不相交），使得sum(A)+sum(B)最大。


思路
先求maxOfLeft[i]，即前i个字符中子数组的最大和（子数组以i为结尾），maxOfRight[i]同理。再修改maxOfLeft和maxOfRight，因为maxOfLeft[i]存储的不是前i个元素中的子数组，而是以i结尾的，修改后maxOfLeft存储前i个元素和最大的子数组。maxOfRight[i]同理。


代码
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> nums) {
        int n = nums.size();
        vector<int> maxOfLeft(n + 1, 0);
        vector<int> maxOfRight(n + 1, 0);
        
        for (int i = 1; i <= n; i++) {
            maxOfLeft[i] = max(nums[i - 1], maxOfLeft[i - 1] + nums[i - 1]);
        }
        for (int i = 1; i <= n; i++) {
            maxOfRight[i] = max(nums[n - i], maxOfRight[i - 1] + nums[n - i]);
        }
        
        int peak = INT_MIN;
        for (int i = 1; i <= n; i++) {
            if (maxOfLeft[i] > peak)
                peak = maxOfLeft[i];
            else
                maxOfLeft[i] = peak;
        }
        peak = INT_MIN;
        for (int i = 1; i <= n; i++) {
            if (maxOfRight[i] > peak)
                peak = maxOfRight[i];
            else
                maxOfRight[i] = peak;
        }
        
        int result = INT_MIN;
        for (int i = 1; i < n; i++) {
            result = max(maxOfLeft[i] + maxOfRight[n - i], result);
        }
        return result;
    }
};

