描述
有一个数组，给定一个数，把小于该数的数组中的数放到左边，大于该数的放到右边。最后返回“左边”最后一个元素的下一个元素的下标。


思路
使用2根指针，left=0，right=N-1。然后一个循环，里面不断对数字进行交换即可。需要注意的是，必须使用left<=right作为判断情况，比如{10,10,X,1,1}，给定5。如果使用left<right的话，到X的位置的时候就停止了，但是X有可能比5大，也有可能比5小。


代码
class Solution {
public:
    void swap(vector<int>& nums, int m, int n) {
        int tmp = nums[m];
        nums[m] = nums[n];
        nums[n] = tmp;
    }
    int partitionArray(vector<int> &nums, int k) {
        int numsLen = nums.size();
        int left = 0;
        int right = numsLen - 1;
        while (left <= right) {
            while (left <= right && nums[left] < k)
                left++;
            while (left <= right && nums[right] >= k)
                right--;
            if (left <= right) {
                swap(nums, left, right);
                left++;
                right--;
            }
        }
        return left;
    }
};

