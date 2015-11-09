描述
求给定集合的所有可能的子集，使得子集的和等于给定值，给定集合的数字可能重复。


思路
看到重复，首先要排序，然后对其dfs。使用i == curr || num[i] != num[i - 1]保证不会产生重复的子集。


代码
class Solution {
public:
 /**
  * @param num: Given the candidate numbers
  * @param target: Given the target number
  * @return: All the combinations that sum to target
  */
    vector<vector<int> > combinationSum2(vector<int> num, int target) {
        vector<vector<int> > result;
        vector<int> item;
        int sumOfItem = 0;
        sort(num.begin(), num.end());
        dfs(0, num, target, sumOfItem, item, result);
        return result;
    }
    
    void dfs(int curr, vector<int>& num, int target, int sumOfItem, vector<int>& item, vector<vector<int> >& result) {
        if (sumOfItem == target) {
            result.push_back(item);
            return;
        }
        if (sumOfItem > target)
            return;
            
        for (int i = curr; i < num.size(); i++) {
            if (i == curr || num[i] != num[i - 1]) {
                sumOfItem += num[i];
                item.push_back(num[i]);
                dfs(i + 1, num, target, sumOfItem, item, result);
                item.pop_back();
                sumOfItem -= num[i];
            }
        }
    }
};

