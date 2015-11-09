描述
同n queens问题，不同的是，n queens问题需要输出所有的棋子摆放可能，该问题只需要输出有多少种可能。


思路
使用一个result变量存储最终的结果，在dfs的时候，到达叶子时result++，因为到达叶子就意味着一种摆放完成了。


代码
class Solution {
public:
    /**
     * Calculate the total number of distinct N-Queen solutions.
     * @param n: The number of queens.
     * @return: The total number of distinct solutions.
     */
    int totalNQueens(int n) {
        vector<int> state(n, -1);
        int result = 0;
        dfs(0, n, state, result);
        return result;
    }
    
    void dfs(int curr, int n, vector<int>& state, int& result) {
        if (curr == n) {
            result++;
            return;
        }
        
        for (int colIndex = 0; colIndex < n; colIndex++) {
            if (isValid(state, curr, colIndex)) {
                state[curr] = colIndex;
                dfs(curr + 1, n, state, result);
                state[curr] = -1;
            }                
        }
    }
    
    bool isValid(vector<int>& state, int rowIndex, int colIndex) {
        for (int i = 0; i < rowIndex; i++) {
            if (state[i] == colIndex || abs(state[i] - colIndex) == abs(i - rowIndex))
                return false;
        }
        return true;
    }
};

