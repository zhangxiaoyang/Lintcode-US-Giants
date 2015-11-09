描述
求在数组中出现次数超过1/k的数。


思路
和majority number ii思路一样，只是我们需要定义k-1个num变量和k-1个count变量，所以使用map存储，key为num，value为出现次数count。同样使用把k个数字合并抵消的方式。最后map里的key即使答案候选集，所以还是需要一次遍历精确计算出最终的答案。


代码
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: As described
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums, int k) {
        map<int, int> counters;
        for (int i = 0; i < nums.size(); i++) {
            if (counters.find(nums[i]) != counters.end())
                counters[nums[i]]++;
            else if (counters.size() < k - 1)
                counters[nums[i]] = 1;
            else {
                for (map<int, int>::iterator i = counters.begin(); i != counters.end(); ) {
                    i->second--;
                    if (i->second == 0)
                        counters.erase(i++);
                    else
                        i++;
                }
            }
        }
        for (map<int, int>::iterator i = counters.begin(); i != counters.end(); i++)
            i->second = 0;
        
        int maxCount = 0;
        int result;
        for (int i = 0; i < nums.size(); i++) {
            if (counters.find(nums[i]) != counters.end()) {
                counters[nums[i]]++;            
                if (counters[nums[i]] > maxCount) {
                    maxCount = counters[nums[i]];
                    result = nums[i];
                }
            }
        }
        return result;
    }
};

