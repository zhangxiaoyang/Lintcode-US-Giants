描述
有一个矩阵，矩阵每一行的数字都是排序好的，矩阵第一列的l数字也是排序好的。给定一个数字，判断这个数字是否在矩阵中。


思路
普通的暴力搜索方法，是O(n2)。这里要充分利用有序这个特点。可以先使用二分查找找到元素所在的行，然后再在这一行内二分查找给定的元素，时间复杂度O(logn)。


代码
class Solution {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int row = searchRow(matrix, target);
        if (row >= 0) {
            int column = searchColumn(matrix[row], target);
            if (column >= 0)
                return true;
        }
        return false;
    }
    int searchRow(vector<vector<int> >& matrix, int target) {
        int left = 0;
        int right = matrix.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (matrix[mid][0] == target)
                return mid;
            if (matrix[mid][0] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left - 1;
    }
    int searchColumn(vector<int>& cells, int target) {
        int left = 0;
        int right = cells.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (cells[mid] == target)
                return mid;
            if (cells[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
};

