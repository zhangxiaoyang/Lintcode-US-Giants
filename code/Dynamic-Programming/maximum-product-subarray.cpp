描述
求数组的子数组，使得子数组的乘积最大。


思路
遍历数组的时候存储当前索引下0~i的子数组乘积最大值dpMax和最小值dpMin，最大值肯定是从max(max(nums[i] * dpMax, nums[i] * dpMin), nums[i])中产生，即要么乘以之前的最大或最小值，要么是自己。


代码
class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: an integer
     */
    int maxProduct(vector<int>& nums) {
        int dpMin = 1;
        int dpMax = 1;
        int result = INT_MIN;
        
        for (int i = 0; i < nums.size(); i++) {
            int tmp = max(max(nums[i] * dpMax, nums[i] * dpMin), nums[i]);
            if (tmp > result)
                result = tmp;
                
            int dpMinTmp = min(min(nums[i] * dpMin, nums[i] * dpMax), nums[i]);
            int dpMaxTmp = max(max(nums[i] * dpMin, nums[i] * dpMax), nums[i]);
            dpMin = dpMinTmp;
            dpMax = dpMaxTmp;
        }
        return result;
    }
};

