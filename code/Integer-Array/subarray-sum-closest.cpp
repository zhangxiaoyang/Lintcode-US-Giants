描述
有一个数组，找出一个子数组（元素连续），使得其元素的和最接近0。如果有多个结果，给出一个即可。


思路
最暴力的方法是O(n2)，但这里要求是O(nlogn)。先说技巧，这里把所有的数组前缀之和都存下来prefixes[N]。这样的话，如果abs(prefixes[x] - prefixes[y])接近0，那么x,y所对应的下标m,n就是答案了！所以，一开始我使用了map，key是prefix（某前缀的和），value是前缀最后一个元素的index。但是这样有很大的问题，因为有可能有多个前缀的和是一样的，这样的话在map里就只存了一个。其实，如果有多个前缀的和一样，说明一定有一个子数组的和是0的！最后，使用的还是prefixes数组，只不过数组的元素是一个pair，里面有2个值，分别是前缀和、index。这样，按照前缀和排序，我们依次比较相邻的2个prefixes[i].first、prefixes[i-1].first，找到abs(prefixes[i].first-prefixes[i-1].first)最小的，就可以了，最后返回对应的prefixes[i].second和prefixes[i-1].second。这个题目花了很长时间，总结来说，看logn要想到排序、查找。还有前缀的方式，如果题目是让求元素和为0的子数组，就可以只花O(n)的时间了，用一个map记录prefixes[i]和index，如果map里已经有prefixes[i]的值了，说明之前记录的值对应的index+1到i这个子数组的和是0，因为前缀相等了！


代码
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySumClosest(vector<int> nums){
        int numsLen = nums.size();
        vector<pair<int, int> > prefixes(numsLen, make_pair(0, 0));
        for (int i = 0; i < numsLen; i++) {
            prefixes[i].first = i == 0
                ? nums[i]
                : prefixes[i - 1].first + nums[i];
            prefixes[i].second = i;
        }
        sort(prefixes.begin(), prefixes.end());
        
        vector<int> result(2, prefixes[0].second);
        int minDiff = abs(prefixes[0].first);
        for (int i = 1; i < numsLen; i++) {
            int diff = abs(prefixes[i].first - prefixes[i - 1].first);
            if (diff < minDiff) {
                minDiff = diff;
                result[0] = min(prefixes[i].second, prefixes[i - 1].second) + 1;
                result[1] = max(prefixes[i].second, prefixes[i - 1].second);
            }
        }
        return result;
    }
};

