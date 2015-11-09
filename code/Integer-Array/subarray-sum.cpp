描述
有一个int数组，找出一个子数组，使得子数组的和是0，子数组的元素连续。比如，{1,2,-1,-1,2}，返回{1,3}，即下标1到3的子数组和为0。


思路
可以使用一个map作为缓存，这样时间复杂度为O(n)。具体方法是，sum=0，遍历数组，不断更新sum+=A[i]。在一次更新sum后，判断map中有没有key=sum的元素，如果没有，则把在map中新加入一个map[sum] = i，表示从0到i的和为key，i为value。如果map中已经有key=sum的元素了，而当前的和也是sum，说明map[sum] + 1到i的子数组和为0，正是因为和是0才导致出现了2次相同的sum。


代码
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        int numsLen = nums.size();
        map<int, int> cache;
        int sum = 0;
        vector<int> result;
        
        for (int i = 0; i < numsLen; i++) {
            sum += nums[i];
            if (sum == 0) {
                result.push_back(0);
                result.push_back(i);
                break;
            }
            else if (cache.find(sum) == cache.end())
                cache[sum] = i;
            else {
                result.push_back(cache[sum] + 1);
                result.push_back(i);
                break;
            }
        }
        
        return result;
    }
};

