描述
有一个有序数组，元素会有重复，从中找出给定元素的下标范围。


思路
通过2次二分查找，分别找到下标的“左值”和“右值”。注意里面的规律，left是左边第一个要查找的元素，right是右边第一个要查找的元素。


代码
class Solution {
    /** 
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    vector<int> searchRange(vector<int> &A, int target) {
        int ALen = A.size();
        vector<int> result(2, -1);
        
        int left = 0;
        int right = ALen - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (A[mid] >= target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        if (ALen > 0 && A[left] == target)
            result[0] = left;
            
        left = 0;
        right = ALen - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (A[mid] <= target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        if (ALen > 0 && A[right] == target)
            result[1] = right;
        return result;
    }
};

