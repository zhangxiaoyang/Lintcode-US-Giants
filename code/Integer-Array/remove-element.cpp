描述
原地去除数组的给定元素，返回新的数组长度。比如数组为{1,2,2,3}，给定元素为2，则把前2个元素赋值为{1,3}，返回新的长度为2。


思路
使用一个index变量，初始值为0，表示数组的0下标及后面的数都是无效的，同时也表示数组的新长度为0。然后，用i遍历数组，如果A[i] != 给定元素，则A[index++] = A[i]，意思是说，我找到了一个非指定元素，我需要保留他，把他放在index的位置，并且index++，此时的新数组长度为1，下标0处已经放了一个元素了。


代码
class Solution {
public:
    /** 
     *@param A: A list of integers
     *@param elem: An integer
     *@return: The new length after remove
     */
    int removeElement(vector<int> &A, int elem) {
        int index = 0;
        int ALen = A.size();
        
        for (int i = 0; i < ALen; i++) {
            if (A[i] != elem)
                A[index++] = A[i];
        }
        
        return index;
    }
};

