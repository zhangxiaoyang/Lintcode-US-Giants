描述
求包含重复元素的所有排列。


思路
看到重复，首先要对输入进行排序。然后对每一个元素dfs，这里需要使用swap的方式，如果我们对第i个元素dfs，直接dfs是不好弄的，所以把第i个元素换到最前面，如果是第2层，就换到第2个元素，再对后面的排序，再dfs。因为最开始的排序并不能保证一直是有序的，swap会改变顺序。这些操作会代表输入，所以每次都要先backup一下，dfs完了再恢复。


代码
class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of unique permutations.
     */
    vector<vector<int> > permuteUnique(vector<int> nums) {
        vector<vector<int> > result;
        vector<int> item;
        sort(nums.begin(), nums.end());
        
        if (nums.size() == 0)
            return result;
            
        dfs(0, nums, item, result);
        return result;
    }
    
    void dfs(int curr, vector<int>& nums, vector<int>& item, vector<vector<int> >& result) {
        if (item.size() == nums.size()) {
            result.push_back(item);
            return;
        }
            
        for (int i = curr; i < nums.size(); i++) {
            if (i == curr || nums[i] != nums[i - 1]) {
                vector<int> backup = nums;
                swap(nums, i, curr);
                sort(nums.begin() + curr + 1, nums.end());
                item.push_back(nums[curr]);
                dfs(curr + 1, nums, item, result);//important
                item.pop_back();
                nums = backup;//important
            }
        }
    }
    
    void swap(vector<int>& v, int i, int j) {
        int tmp = v[i];
        v[i] = v[j];
        v[j] = tmp;
    }
};

