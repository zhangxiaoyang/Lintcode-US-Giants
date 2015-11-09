描述
有一个数组，从中找到2个数，使得他们的和等于给定的一个数。最后返回这2个数的数组下标。


思路
首先想到的是把数组排序，但是下标就乱了，而且这个题目希望我们使用O(n)时间解决。方法是，使用一个map，存储元素的值和对应的下标。一次遍历数组，一边遍历，一边更新map，并且从map中查找有没有一个数和当前的A[i]之和是target。因为是2 sum嘛，总会在第2个数的时候可以从map中找到第1个数。


代码
class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        map<int, int> cache;
        int numsLen = nums.size();
        vector<int> result;
        for (int i = 0; i < numsLen; i++) {
            int num = target - nums[i];
            if (cache.find(num) != cache.end()) {
                result.push_back(cache[num] + 1);
                result.push_back(i + 1);
                return result;
            }
            cache[nums[i]] = i;
        }
        return result;
    }
};

