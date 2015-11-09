描述
从给定数字数组从取两个子数组A和B（不相交），使得其abs(sum(A) - sum(B))最大。


思路
minOfLeft[i]表示前i个元素的子数组的最小和，maxOfLeft[i]表示前i个元素的子数组的最大和。minOfRight、maxOfRight同理。要想abs(sum(A) - sum(B))最大，则A最小B最大或者A最大B最小。


代码
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer indicate the value of maximum difference between two
     *          Subarrays
     */
    int maxDiffSubArrays(vector<int> nums) {
        int n = nums.size();
        vector<int> minOfLeft(n + 1, 0);
        vector<int> maxOfLeft(n + 1, 0);
        vector<int> minOfRight(n + 1, 0);
        vector<int> maxOfRight(n + 1, 0);
        
        for (int i = 1; i <= n; i++) {
            minOfLeft[i] = min(nums[i - 1], minOfLeft[i - 1] + nums[i - 1]);
            maxOfLeft[i] = max(nums[i - 1], maxOfLeft[i - 1] + nums[i - 1]);
        }
        for (int i = 1; i <= n; i++) {
            minOfRight[i] = min(nums[n - i], minOfRight[i - 1] + nums[n - i]);
            maxOfRight[i] = max(nums[n - i], maxOfRight[i - 1] + nums[n - i]);
        }
        
        int result = 0;
        for (int i = 1; i < n; i++) {
            result = max(abs(minOfLeft[i] - maxOfRight[n - i]), result);
            result = max(abs(maxOfLeft[i] - minOfRight[n - i]), result);
        }
        return result;
    }
};

