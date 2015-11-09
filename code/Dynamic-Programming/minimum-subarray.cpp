描述
求数组的子数组，使其和最小。


思路
随着遍历数组，dpMin表示当前（以i结尾的子数组）最小的和。如果dpMin = min(nums[i] + dpMin, nums[i])。


代码
class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: A integer denote the sum of minimum subarray
     */
    int minSubArray(vector<int> nums) {
        int n = nums.size();
        int dpMin = 0;
        int result = INT_MAX;
        for (int i = 0; i < n; i++) {
            dpMin = min(dpMin + nums[i], nums[i]);
            
            if (dpMin < result)
                result = dpMin;
        }
        return result;
    }
};

