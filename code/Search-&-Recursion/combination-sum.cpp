描述
对定一堆数，从中选若干个使得和为给定的sum，每个数可以选择多次。


思路
先对给定的数进行排序并去重复。假设某层的结点为x，则x的下层的结点值为大于等于x，此处不可产生小于
x的值，因为会造成重复。之前先对数进行排序并去重就是为了这一点。策略还是push当前的结点，然后递归其子结点，完了以后在pop当前结点。


代码
class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
    vector<vector<int> > combinationSum(vector<int> candidates, int target) {
        vector<vector<int> > result;
        vector<int> item;
        sort(candidates.begin(), candidates.end());
        candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
        int sumOfItem = 0;
        
        dfs(candidates, target, 0, sumOfItem, item, result);
        return result;
    }
    
    void dfs(vector<int>& candidates, int target, int curr, int sumOfItem, vector<int>& item, vector<vector<int> >& result) {
        if (sumOfItem == target) {
            result.push_back(item);
            return;
        }
        if (sumOfItem > target)
            return;
            
        for (int i = curr; i < candidates.size(); i++) {
            item.push_back(candidates[i]);
            sumOfItem += candidates[i];
            dfs(candidates, target, i, sumOfItem, item, result);
            sumOfItem -= candidates[i];
            item.pop_back();
        }        
    }
};

