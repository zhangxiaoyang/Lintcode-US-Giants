描述
在一个数组中，有一个数字出现了超过一半的次数，找出这个数字。


思路
通过一个count来记录，然后遍历这个数组，如果num[i] == result，则count++；否则，count--。如果count==0，则重新设置result = num[i]。


代码
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
        int result;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                result = nums[i];
                count++;
            }
            else {
                if (nums[i] == result)
                    count++;
                else
                    count--;
            }
        }
        
        return result;
    }
};

