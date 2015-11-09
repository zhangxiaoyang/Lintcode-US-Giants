描述
在nxn的棋盘上放置n个棋子，使得任意两个都不在同一行、同一列、同一斜线。


思路
先放第一个棋子，然后再基于其放第二个，再放第三个...。重新改变第一个棋子的位置，再放一遍...。所以需要dfs。关键是如何基于以前的放置，来放下一个，使得满足要求。这里需要使用state数组，state[i]的值表示第i行放置棋子的位置。每放一个棋子，就改变state[i]。在放下一个（其实就是下一行，放置的顺序是从0行开始，一行一行的放）棋子的时候，假设放到第i行，需要判断从第0列开始判断，是不是满足要求，判断方法是代码中的isValid。因为是按行放的棋子，所以这里只需要一次遍历state就可以找一个合适的列值。


代码
class Solution {
public:
    /**
     * Get all distinct N-Queen solutions
     * @param n: The number of queens
     * @return: All distinct solutions
     * For example, A string '...Q' shows a queen on forth position
     */
    vector<vector<string> > solveNQueens(int n) {
        vector<int> state(n, 0);
        vector<string> item;
        vector<vector<string> > result;
        
        dfs(0, state, item, result);
        return result;
    }
    
    void dfs(int rowIndex,  vector<int>& state, vector<string>& item, vector<vector<string> >& result) {
        int n = state.size();
        if (item.size() == n) {
            result.push_back(item);
            return;
        }
        
        for (int colIndex = 0; colIndex < state.size(); colIndex++) {
            if (isValid(state, rowIndex, colIndex)) {
                string row(n, '.');
                row[colIndex] = 'Q';
                state[rowIndex] = colIndex;
                item.push_back(row);
                dfs(rowIndex + 1, state, item, result);
                item.pop_back();
            }
        }
    }
    
    bool isValid(vector<int>& state, int rowIndex, int colIndex) {
        for (int i = 0; i < rowIndex; i++) {
            if (state[i] == colIndex || abs(i - rowIndex) == abs(state[i] - colIndex))
                return false;
        }
        return true;
    }
};

