描述
有一个集合，数字可能重复，求其所有的子集。


思路
看到重复，自然就想到了先排序，这样可以防止在后面的过程重复产生一样的子集。然后通过这个判断i == curr ||  s[i] != s[i - 1]来保证产生不重复的子集，注意这里的i == curr，对于1,1,2这个的子集，肯定是会有1,1的，即第一层产生了1以后，下一层还是1，尽管和上一层的1相等，但是我们还是不能跳过他。


代码
class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsetsWithDup(const vector<int> &S) {
        vector<int> s = S;
        sort(s.begin(), s.end());
        vector<vector<int> > result;
        vector<int> item;
        result.push_back(item);
        
        dfs(0, s, item, result);
        return result;        
    }
    
    void dfs(int curr, vector<int>& s, vector<int>& item, vector<vector<int> >& result) {
        for (int i = curr; i < s.size(); i++) {
            if (i == curr ||  s[i] != s[i - 1]) {
                item.push_back(s[i]);
                result.push_back(item);
                dfs(i + 1, s, item, result);
                item.pop_back();
            }
        }
    }
};

