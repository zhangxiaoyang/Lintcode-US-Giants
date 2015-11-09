描述
给定一个数组，从里面找3个数，使得他们的和和给定的target最接近。


思路
暴力方法是O(n3)，题目要求O(n2)完成。可以先对数组排序，O(nlogn)。然后外层使用一个循环i，内层使用2个指针j和k，分别指向i + 1和N-1，然后不断移动j和k，即j++、k--（夹逼）。


代码
class Solution {
public:    
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> nums, int target) {
        sort(nums.begin(), nums.end());
        int numsLen = nums.size();
        int result = 0;
        int minDiff = INT_MAX;
        for (int i = 0; i < numsLen; i++) {
            int j = i + 1;
            int k = numsLen - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                int diff = abs(sum - target);
                if (diff < minDiff) {
                    minDiff = diff;
                    result = sum;
                }
                if (diff == 0)
                    return sum;
                if (sum <= target)
                    j++;
                else
                    k--;
            }
        }
        return result;
    }
};

