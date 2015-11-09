描述
求在数组中出现次数超过1/2的数。


思路
使用和majority number类似的方法，“合并抵消”。使用2个变量num1, num2和相应的计数器，count1, count2。遍历数组，如果num[i]和num1和num2三者都各不相同，则count1--,count2--。如果num1或者num2为0，则把num[i]存入进去，相应的countX++。最后，不断的合并抵消，num1和num2中有一个即为答案。最后还需要遍历一次数组，精确计算出num1和num2各出现多少次。


代码
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number occurs more than 1/3.
     */
    int majorityNumber(vector<int> nums) {
        int num1 = INT_MIN;
        int num2 = INT_MIN;
        int count1 = 0;
        int count2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == num1)
                count1++;
            else if (nums[i] == num2)
                count2++;
            else if (count1 == 0) {
                num1 = nums[i];
                count1++;
            }
            else if (count2 == 0) {
                num2 = nums[i];
                count2++;
            }
            else {
                count1--;
                count2--;
            }
        }
        
        count1 = 0;
        count2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == num1)
                count1++;
            if (nums[i] == num2)
                count2++;
        }
        
        return count1 > count2 ? num1 : num2;
    }
};

