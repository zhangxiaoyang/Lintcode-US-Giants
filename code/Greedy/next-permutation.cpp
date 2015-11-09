描述
求给定排列的下一个排列。


思路
从后往前找到第一个满足A[i] < A[i + 1]的关系，然后再从后往前找到一个A[j] > A[i] && j > i，交换A[i]和A[j]，reverse i+1及其后面的数。


代码
class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's next permuation
     */
    vector<int> nextPermutation(vector<int> &nums) {
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                int j = nums.size() - 1;
                while (j > i) {
                    if (nums[j] > nums[i]) {
                        swap(nums, i, j);
                        break;
                    }
                    j--;
                }
                reverse(nums.begin() + i + 1, nums.end());
                return nums;
            }   
        }
        reverse(nums.begin(), nums.end());
        return nums;
    }
    void swap(vector<int>& v, int i, int j) {
        int tmp = v[i];
        v[i] = v[j];
        v[j] = tmp;
    }
};

