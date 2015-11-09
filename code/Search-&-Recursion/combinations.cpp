描述
求所有的组合C(n,k)，从1~n中取k个数。


思路
dfs搜索，根结点可以是1~n，对于第一层的某一个结点再产生第二层的结点，以此类推。当层数为k时，即停止并返回到上一层，对于上一层pop出刚才在下层添加的元素，继续选择上层中可选的下一个结点。


代码
class Solution {
public:
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > result;
        vector<int> item;
        dfs(1, n, k, item, result);
        return result;
    }
    
    void dfs(int curr, int n, int k, vector<int>& item, vector<vector<int> >& result) {
        if (item.size() == k) {
            result.push_back(item);
            return;
        }
        
        for (int i = curr; i <= n; i++) {
            item.push_back(i);
            dfs(i + 1, n, k, item, result);
            item.pop_back();
        }
    }
};

