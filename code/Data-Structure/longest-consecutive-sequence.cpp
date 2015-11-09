描述
计算无序数字数组的最长连续序列，例如，[100, 4, 200, 1, 3, 2]的序列为[1, 2, 3, 4]，一共4个，返回4。


思路
先一次遍历把所有的数字放到哈希表，key为数字，value为true，value表示该数字还未被使用。然后再次遍历数组，对于num[i]尝试去哈希表寻找num[i]±x，如果有则把哈希表对应值置为false，并将结果加1。


代码
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return an integer
     */
    int longestConsecutive(vector<int> &num) {
        int n = num.size();
        unordered_map<int, bool> cache;
        for (int i = 0; i < n; i++)
            cache[num[i]] = true;
        
        int result = 0;
        for (unordered_map<int, bool>::iterator i = cache.begin(); i != cache.end(); i++) {
            int value = i->first;
            int tmp = 0;
            while (cache.find(value) != cache.end() && cache[value]) {
                cache[value--] = false;
                tmp++;
            }
            value = i->first + 1;
            while (cache.find(value) != cache.end() && cache[value]) {
                cache[value++] = false;
                tmp++;
            }
            result = max(tmp, result);
        }
        return result;
    }
};

