描述
有两个排序好的数组，将他们合并成一个有序的数组。


思路
开一个新的数组，大小为两个数组长度和。然后分别设置i和j指向两个数组，一边遍历一边往新数组填数。


代码
class Solution {
public:
    /**
     * @param A and B: sorted integer array A and B.
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        int ALen = A.size();
        int BLen = B.size();
        
        vector<int> result(ALen + BLen, 0);
        int i = 0;
        int j = 0;
        int index = 0;
        while (i < ALen || j < BLen) {
            if (i >= ALen) {
                result[index++] = B[j++];
                continue;
            }
            if (j >= BLen) {
                result[index++] = A[i++];
                continue;
            }
            if (A[i] < B[j])
                result[index++] = A[i++];
            else
                result[index++] = B[j++];
        }
        return result;
    }
};

