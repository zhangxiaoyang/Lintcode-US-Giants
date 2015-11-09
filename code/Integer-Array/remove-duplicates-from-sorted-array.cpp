描述
有一个排好序的数组，删除其中重复的元素，使得重复的元素只保留一个，原地进行删除，返回新的数组长度。比如，A={1,2,2,3}，需要把A变成{1,2,3}，返回长度3。


思路
设置一个index下标，最开始指向0，然后使用i遍历数组，从1开始遍历。如果和index的元素相等，则继续i++，否则就A[++index] = A[i]这样index就指向了新的元素。最终，返回index + 1就是新数组的长度。在这里，index可以理解为“我指向新数组的最后一个元素，随着i的遍历，不断扩张”。


代码
class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        int numsLen = nums.size();
        if (numsLen <= 1)
            return numsLen;
            
        int index = 0;
        for (int i = 1; i < numsLen; i++) {
            if (nums[i] != nums[index])
                nums[++index] = nums[i];
        }
        return index + 1;
    }
};

