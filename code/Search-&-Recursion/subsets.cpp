描述
给定一个包含不重复数字的集合，产生所有的子集。


思路
因为每一个数字都不相同，所有即可对每个数字dfs。


代码
class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsets(vector<int> &nums) {
        vector<vector<int> > result;
        vector<int> item;
        result.push_back(item);
        
        dfs(0, nums, item, result);
        return result;
    }
    
    void dfs(int curr, vector<int>& nums, vector<int>& item, vector<vector<int> >& result) {
        for (int i = curr; i < nums.size(); i++) {
            item.push_back(nums[i]);
            result.push_back(item);
            dfs(i + 1, nums, item, result);
            item.pop_back();
        }
    }
};

