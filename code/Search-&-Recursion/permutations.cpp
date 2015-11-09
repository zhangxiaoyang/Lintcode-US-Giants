描述
给定不重复的集合，求所有可能的排列。


思路
因为集合的数字各不相同，所以可以对每个数dfs。如果对第k层的第i个数dfs，则先swap第i个元素到第k个位置，dfs完了再swap成原来的样子。


代码
class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int> > permute(vector<int> nums) {
        vector<vector<int> > result;
        vector<int> item;
        
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
            swap(nums, i, curr);
            item.push_back(nums[curr]);
            dfs(curr + 1, nums, item, result);//important
            item.pop_back();
            swap(nums, i, curr);//important
        }
    }
    
    void swap(vector<int>& v, int i, int j) {
        int tmp = v[i];
        v[i] = v[j];
        v[j] = tmp;
    }
};

