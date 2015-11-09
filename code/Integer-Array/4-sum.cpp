描述
有一个数组，从中选4个数字，使得他们的和等于给定的数。


思路
这个和3sum的方法一模一样，先把数组排序，开2层循环，内层使用2个指针，分别从左右两侧夹逼。需要注意的是，为了去重，在最内层的循环中，需要看nums[m] == nums[m-1]是否成立，如果成立，则continue，同时m++。


代码
class Solution {
public:
    /**
     * @param numbers: Give an array numbersbers of n integer
     * @param target: you need to find four elements that's sum of target
     * @return: Find all unique quadruplets in the array which gives the sum of 
     *          zero.
     */
    vector<vector<int> > fourSum(vector<int> nums, int target) {
        vector<vector<int> > result;
        int numsLen = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < numsLen; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < numsLen; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                int m = j + 1;
                int n = numsLen - 1;
                while (m < n) {
                    if (m > j + 1 && nums[m] == nums[m - 1]) {
                        m++;
                        continue;
                    }
                    int sum = nums[i] + nums[j] + nums[m] + nums[n];
                    if (sum == target) {
                        vector<int> tmp;
                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[j]);
                        tmp.push_back(nums[m]);
                        tmp.push_back(nums[n]);
                        result.push_back(tmp);
                        m++;
                        n--;
                    }
                    else if (sum < target)
                        m++;
                    else
                        n--;
                }
            }
        }
        return result;
    }
};

