描述
从一个排序的数组中删除重复的元素，重复3次或以上才删除。最后返回新数组的元素个数。


思路
使用index指针，指向下标2，表示下一个要存储的数组放到index的位置。然后使用i进行遍历，初始值为2。如果A[index-2] != A[i]，则把A[i]赋值到index下标。最后返回的时候，index的值就是新数组元素的个数。


代码
class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        int numsLen = nums.size();
        if (numsLen <= 2)
            return numsLen;
            
        int index = 2;
        for (int i = index; i < numsLen; i++) {
            if (nums[i] != nums[index - 2])
                nums[index++] = nums[i];
        }
        return index;
    }
};

